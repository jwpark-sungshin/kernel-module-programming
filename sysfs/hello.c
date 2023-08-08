#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
extern int myvariable;
static int __init hello_init(void) {    
	printk("hello_init(). hello %d\n", myvariable);    
	return 0;
}
static void __exit hello_exit(void) {
	printk("hello_exit().\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1.0");
