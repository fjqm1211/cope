#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
 pid_t mypid, parentpid;
 mypid = getpid();
 parentpid = getppid();

 printf("PID is %ld\n",(long)mypid);
 printf("PPID is %ld\n",(long)parentpid);
 
 return 0;
}
