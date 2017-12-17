#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    pid_t  pid = fork();
    
    int status = 1;

    switch (pid){
    case -1://error
        perror("fork");
        exit(0); 
    case 0:// child process
        printf("[child] pid: %ld,ppid : %ld\n",(long)getpid(),(long)getppid());
        exit(123);
        break;
    default:
        printf("[parent] pid: %ld, ppid : %ld\n",(long)getpid(),(long)getppid());
        wait(&status);
        printf("[parent] status : %d\n",WEXITSTATUS(status));
        break;
    }

}
