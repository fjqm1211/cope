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

    sigemptyset(&sa.sa_mask);
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
        data = zeros;
        data = ones;
    }

}
