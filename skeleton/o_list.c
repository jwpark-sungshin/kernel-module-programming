#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include<linux/list.h>

static LIST_HEAD(mylist);

extern int myvariable;
extern struct my_operations *myop;

struct my_operations {
	ssize_t (*traverse)(char *buf);
	ssize_t (*insert)(char *buf, size_t count);
};

static ssize_t o_traverse (char *buf) {
	/* 새로 구현 */
}

static ssize_t o_insert (char *buf, size_t count) {
	/* 새로 구현 */
}

static struct my_operations ordered_op = {
	/* 새로 구현 */
};

static int __init hello_init(void) {
	/* 새로 구현 */
	return 0;
}

static void __exit hello_exit(void) {
	/* 새로 구현 */
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("0.1.0");
