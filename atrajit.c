#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h> // For printk()
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Atrajit");
MODULE_DESCRIPTION("Our first dynamic loadable kernel module");

static struct proc_dir_entry *proc_entry;

ssize_t atrajit_read(struct file *,
                     char __user *,
                     size_t,
                     loff_t *);

ssize_t atrajit_read(struct file *file_pointer,
                     char __user *user_space_buffer,
                     size_t count,
                     loff_t *offset)
{
    char msg[] = "Ack\n";
    size_t len = strlen(msg);
    int result;

    if (*offset >= len)
    {
        return 0;
    }

    *offset += len;

    result = copy_to_user(user_space_buffer, msg, len);

    printk("atrajit read\n");
    return len;
}

static struct proc_ops driver_proc_ops = {
    .proc_read = atrajit_read

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
