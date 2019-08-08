#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
#include <scsi/scsi_host.h>

typedef int (*syno_libata_index_get_p)(struct Scsi_Host *host, uint channel, uint id, uint lun);
static int syno_libata_index_get(struct Scsi_Host *host, uint channel, uint id, uint lun);

static syno_libata_index_get_p xpenology_syno_libata_index_get = NULL;

static int syno_libata_index_get (struct Scsi_Host *host, uint channel, uint id, uint lun)
{
	pr_info("calling syno_libata_index_get.\n");
	return xpenology_syno_libata_index_get(host, channel, id, lun);
}
EXPORT_SYMBOL(syno_libata_index_get);

static int lookup_kernel_symbols(void *data, const char *namebuf, struct module *module, unsigned long address)
{
	if ((module == NULL) && (strcmp(namebuf, "syno_libata_index_get") == 0)){
		xpenology_syno_libata_index_get = (syno_libata_index_get_p)address;
	}
	return 0;
}

static int __init xpenology_init(void) {
	kallsyms_on_each_symbol(lookup_kernel_symbols, NULL);

	if (xpenology_syno_libata_index_get == 0){
		pr_err("Unable to find syno_libata_index_get");
		return -EINVAL;
	}
	pr_info("Found syno_libata_index_get at address 0x%lx.\n", (unsigned long)xpenology_syno_libata_index_get);

	return 0;
}

static void xpenology_exit(void){
}

module_init(xpenology_init);
module_exit(xpenology_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Blonďák <blondak@neser.cz>");
MODULE_DESCRIPTION("Exports some syno_ symbols");
MODULE_VERSION("0.1");

