#KERNEL_DIR=/lib/modules/$(shell uname -r)/build
KERNEL_DIR = $(PWD)/../linux-3.10.x
obj-m += xpenology.o

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

