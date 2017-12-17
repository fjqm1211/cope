#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    
    pid_t pid=fork();
       
    switch(pid){
    case -1://error
        exit(0);
    case 0:
        execl("/bin/ps","ps","-ef",NULL);
    default:
        wait(NULL);
        printf("[parnet] terminated\n");
    }
    return 0;
}
