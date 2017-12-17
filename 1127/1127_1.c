#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void my_handler(int sig)
{
    printf("Ouch\n");
}

int main()
{
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);//non blocking
    sa.sa_flags = 0; //default 0
    sa.sa_handler = my_handler;

    if (sigaction(SIGINT,&sa, NULL) == -1){
        perror("sigaction");
        exit(0);
    }
    

    while(1)
    {
        printf("my pid = %ld\n",(long)getpid());
        sleep(1);
    }

    return 0;
}
