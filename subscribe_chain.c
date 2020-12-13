#include <linux/notifier.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>  
#include <linux/fs.h>    

extern int register_test_notifier(struct notifier_block *nb);
#define EVENT_CODE 0x9527

int invoke_event(struct notifier_block *nb, unsigned long event, void *v) {
	switch(event) {
	case EVENT_CODE:
		printk(KERN_DEBUG "publish event code %d triggered target function\n", EVENT_CODE);
		break;
	}
	return NOTIFY_DONE;
}


static struct notifier_block notifier = {
	.notifier_call = invoke_event
};

static int __init subscribe_chain_init(void)
{
    printk(KERN_DEBUG "insert subscribe chain into kernel\n");
    register_test_notifier(&notifier);
    return 0;
}

static void __exit subscribe_chain_exit(void)
{
    printk(KERN_DEBUG "remove subscribe chain from kernel\n");
}

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("breaksourcecode");
module_init(subscribe_chain_init);
module_exit(subscribe_chain_exit);


