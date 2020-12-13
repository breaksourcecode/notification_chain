obj-m := base_chain.o publish_chain.o subscribe_chain.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd) 

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm *.ko *.mod *.o *.order *.symvers *.mod.c
