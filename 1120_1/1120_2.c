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
        for(int j = 0; j < 10000; j++){
            printf("[child] number : %d\n",j);
            fflush(NULL);
        }
        break;
    default:
        printf("[parent] pid: %ld, ppid : %ld\n",(long)getpid(),(long)getppid());
        for(int i =0; i < 10000; i++){
            printf("[parent] number : %d\n",i);
            fflush(NULL);
        }
        wait(NULL);
        break;
    }

}
