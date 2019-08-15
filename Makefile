# Copyright (c) 2000-2017 Synology Inc. All rights reserved.

XPENOLOGY_KERNEL_SYMBOLS= xpenology.ko

all: $(XPENOLOGY_KERNEL_SYMBOLS)

obj-m := xpenology.o

$(XPENOLOGY_KERNEL_SYMBOLS):
	make -C $(KSRC) M=$(PWD) modules

install: $(XPENOLOGY_KERNEL_SYMBOLS)
	mkdir -p $(DESTDIR)/xpenology-kernel-symbols/
	install $< $(DESTDIR)/xpenology-kernel-symbols/

clean:
	rm -rf *.o $(XPENOLOGY_KERNEL_SYMBOLS) *.cmd
