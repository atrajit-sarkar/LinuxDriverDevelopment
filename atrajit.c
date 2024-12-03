#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> // For printk()
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Atrajit");
MODULE_DESCRIPTION("Our first dynamic loadable kernel module");

static struct proc_dir_entry *proc_entry;
static struct proc_ops driver_proc_ops = {

};

static int __init atrajit_module_init(void)
{
    pr_info("atrajit_module_init:entry\n");

    proc_entry = proc_create(
        "atrajit_driver",
        0,
        NULL,
        &driver_proc_ops);

    pr_info("atrajit_module_init:exit\n");

    return 0;
}

static void __exit atrajit_module_exit(void)
{
    pr_info("atrajit_module_exit:entry\n");
    proc_remove(proc_entry);
    pr_info("atrajit_module_exit:exit\n");
}

module_init(atrajit_module_init);
module_exit(atrajit_module_exit);
