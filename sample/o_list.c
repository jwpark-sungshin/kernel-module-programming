#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

static LIST_HEAD(mylist);

struct item {
	int data;
	struct list_head list;
};

extern int myvariable;
extern struct my_operations *myop;

struct my_operations {
	ssize_t (*traverse)(char *buf);
	ssize_t (*insert)(char *buf, size_t count);
};

static ssize_t o_traverse (char *buf) {
	struct item *pos;
	int i = 0;
	ssize_t len = 0;
	list_for_each_entry(pos, &mylist, list) {
		len += sprintf(buf+len, "list[%d]: %d\n", i++, pos->data);
	}
	return len;
}

static ssize_t o_insert (char *buf, size_t count) {
	struct item *new_item = kmalloc(sizeof(struct item), GFP_KERNEL);
    sscanf(buf, "%du", &new_item->data); 
	list_add_tail(&new_item->list, &mylist);
	myvariable++;
    return count; 
}

static struct my_operations ordered_op = {
	.traverse = o_traverse,
	.insert = o_insert
};

static int __init hello_init(void) {
	myop = &ordered_op;
	printk("hello_init(). %d \n", myvariable);    
	return 0;
}

static void __exit hello_exit(void) {
	printk("hello_exit().\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("0.1.0");
