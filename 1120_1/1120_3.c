#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    pid_t  pid = fork();
    
    int a = 1;

    switch (pid){
    case -1://error
        perror("fork");
        exit(0); 
    case 0:// child process
        printf("[child] pid: %ld,ppid : %ld\n",(long)getpid(),(long)getppid());
        
        break;
    default:
        printf("[parent] pid: %ld, ppid : %ld\n",(long)getpid(),(long)getppid());
        for(::)
        wait(NULL);
        break;
    }

}
