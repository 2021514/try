obj-m += taskDetailsModule.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(Pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean