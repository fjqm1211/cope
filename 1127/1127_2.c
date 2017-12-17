#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void my_handler(int sig)
{
    printf("Ouch\n");
}

void my_handler_term(int sig)
{
    printf("Good Bye\n");
    exit(0);
}

int main()
{
    struct sigaction sa;
    struct sigaction sb;

    sigemptyset(&sa.sa_mask);//non blocking
    sa.sa_flags = 0; //default 0
    sa.sa_handler = my_handler;

    sigemptyset(&sb.sa_mask);
    sb.sa_flags = 0;
    sb.sa_handler = my_handler_term;

    if (sigaction(SIGINT,&sa, NULL) == -1){
        perror("sigaction");
        exit(0);
    }
    
    if (sigaction(SIGTERM,&sb, NULL)== -1){
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
