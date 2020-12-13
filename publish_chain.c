#include <linux/notifier.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h> 
#include <linux/fs.h> 

extern int call_test_notifiers(unsigned long val, void *v);
#define EVENT_CODE 0x9527


static int __init publish_chain_init(void)
{
    printk(KERN_DEBUG "publish event\n");
    call_test_notifiers(EVENT_CODE, "no_use");
    return 0;
}

static void __exit publish_chain_exit(void)
{
    printk(KERN_DEBUG "remove publish chain from kernel\n");
}

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("breaksourcecode");

module_init(publish_chain_init);
module_exit(publish_chain_exit);
