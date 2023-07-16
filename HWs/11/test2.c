#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/list.h>
#include<linux/types.h>
#include<linux/slab.h>

struct birthday {
    int day;
    int month;
    int year;
    struct list_head list;
};

// declaring birthday_list
static LIST_HEAD(birthday_list);

int simple_init(void) {
    
    struct birthday *person1;
    struct birthday *person2;
    struct birthday *person3;
    struct birthday *person4;
    struct birthday *person5;

    struct birthday *ptr;

    printk(KERN_INFO "Loading Module Birthday\n");

    person1 = kmalloc(sizeof(*person1), GFP_KERNEL);
    person1->day = 1;
    person1->month = 12;
    person1->year = 1380;
    INIT_LIST_HEAD(&person1->list);
    list_add_tail(&person1->list, &birthday_list);

    person2 = kmalloc(sizeof(*person2), GFP_KERNEL);
    person2->day = 2;
    person2->month = 11;
    person2->year = 1381;
    INIT_LIST_HEAD(&person2->list);
    list_add_tail(&person2->list, &birthday_list);

    person3 = kmalloc(sizeof(*person3), GFP_KERNEL);
    person3->day = 3;
    person3->month = 10;
    person3->year = 1382;
    INIT_LIST_HEAD(&person3->list);
    list_add_tail(&person3->list, &birthday_list);

    person4 = kmalloc(sizeof(*person4), GFP_KERNEL);
    person4->day = 4;
    person4->month = 9;
    person4->year = 1383;
    INIT_LIST_HEAD(&person4->list);
    list_add_tail(&person4->list, &birthday_list);

    person5 = kmalloc(sizeof(*person5), GFP_KERNEL);
    person5->day = 5;
    person5->month = 8;
    person5->year = 1384;
    INIT_LIST_HEAD(&person5->list);
    list_add_tail(&person5->list, &birthday_list);

    list_for_each_entry(ptr, &birthday_list, list) {
        printk(KERN_INFO "Birthday: %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
    }

    return 0;
}

void simple_exit(void) {
    struct birthday *ptr, *next;

    printk(KERN_INFO "Removing Module Birthday\n");

    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        printk(KERN_INFO "Removing Birthday: %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
        list_del(&ptr->list);
        kfree(ptr);
    }
}

module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");