#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cred.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <sched.h>

static int ID_process = 0;

module_param(ID_process, int , 0660);

static inti__init new_module_init(void){
    struct task_struct *details;
    details = pid_task(find_vpid(ID_process), PIDTYPE_PID);
    printk("pid: %d\n", processDetails->pid);
    printf("p_gid: %d\n", processDetails->group_leader->pid);
    printk("uid: %d\n",processDetails->cred->uid);
    printk("Command_path: %s\n", processDetails->comm);
    return 0;
}
static void __exit new_module_exit(void){
    printk("Exiting!");
}
MODULE_LICENSE("GPL");

module_init(new_module_init);
module_exit(new_module_exit);


