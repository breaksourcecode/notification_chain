#include <linux/notifier.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h> 
#include <linux/fs.h>    


static RAW_NOTIFIER_HEAD(test_chain);


static int call_test_notifiers(unsigned long val, void *v) {

	return raw_notifier_call_chain(&test_chain,val,v);
}

EXPORT_SYMBOL(call_test_notifiers);

static int register_test_notifier(struct notifier_block *nb) {
	int err;
	err = raw_notifier_chain_register(&test_chain,nb);
	if (err)
		return err;
	return 0;
}


EXPORT_SYMBOL(register_test_notifier);

static int __init base_chain_init(void) {
	printk(KERN_DEBUG "insert base chain into kernel\n");
	return 0;
}

static void __exit base_chain_exit(void) {
	printk(KERN_DEBUG "remove base chain from kernel\n");

}

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("breaksourcecode");

module_init(base_chain_init);
module_exit(base_chain_exit);
