#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> // For printk()

MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Atrajit");
MODULE_DESCRIPTION("Our first dynamic loadable kernel module");

static int __init atrajit_module_init(void)
{
    pr_info("Hello, World!\n");
    return 0;
}

static void __exit atrajit_module_exit(void)
{
    pr_info("Good, Bye!\n");
}

module_init(atrajit_module_init);
module_exit(atrajit_module_exit);
