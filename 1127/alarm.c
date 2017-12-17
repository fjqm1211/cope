#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int sig){
    printf("Alram aeeived!\n");
    alarm(1);
}

int main()
{
    struct sigaction sa;
    
    sigemptyset(&sa.sa_mask);
   sa.sa_flags = 0;
    sa.sa_handler = my_handler;
    
    if (sigaction(SIGALRM,&sa,NULL)== -1){
        perror("sigaction");
        exit(0);
    }
    alarm(1);
    while(1){
        
    }
}
