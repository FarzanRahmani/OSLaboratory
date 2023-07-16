#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
// #include<sys/wait.h>

int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    // printk(KERN_INFO "Hello World\n");
    return 0;
}

void simple_exit(void)
{
    printk(KERN_INFO "Removing Module\n");
    // printk(KERN_INFO "Goodbye World\n");
}

module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");