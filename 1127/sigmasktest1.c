#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct two_double{
    double a;
    double b;
}data;

void signal_handler(int sig)
{
    printf("%f, %f\n",data.a,data.b);
    alarm(1);
}

int main(){

    struct sigaction sa;
    static struct two_double zeros={0.0,0.0}, ones = {1.0,1.0};
    sigset_t sigset;

    sigemptyset(&sa.sa_mask);
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);
    sa.sa_flags = 0;
    sa.sa_handler = signal_handler;
    if(sigaction(SIGALRM,&sa,NULL) == -1)
    {
        perror("sigaction");
        exit(0);
    }
    data = zeros;
    alarm(1);
    while(1)
    {
        sigprocmask( SIG_BLOCK, &sigset, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &sigset, NULL);
        sigprocmask(SIG_BLOCK, &sigset, NULL);
        data = ones;
        sigprocmask(SIG_UNBLOCK, &sigset, NULL);
    }

}
