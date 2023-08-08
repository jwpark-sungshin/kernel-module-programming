obj-m += hello-sysfs.o
obj-m += o_list.o
obj-m += uo_list.o
hello:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
