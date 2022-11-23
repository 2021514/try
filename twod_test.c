#include <stdio.h>
#include <sys/syscalls.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define TWOD_COPY_SYSCALL 452

void check_equal(int lhs[5][5], int rhs[5][5])
{
    int i;
    int j;
    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            if(lhs[i][j]!=rhs[i][j]){
                printf("Error : LHS[%d][%d] != RHS[%d][%d]\n", i, j, i, j);
                return;
            }
        }
    }
    printf("Message : Success LHS = RHS \n");
}
int main()
{
    int src_arr[][] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int dest_arr[5][5]; 



    long sys_call_status;

    sys_call_status = syscall(TWOD_COPY_SYSCALL, src_arr, dest_arr, 5, 5);

    if (sys_call_status != EFAULT)
    {
        printf("Message : System Call 452 successfully invoked \n");
        check_equal(src_arr, dest_arr);
    }

    return 0;
}
