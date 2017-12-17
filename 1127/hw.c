#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct two_double{
    double a;
    double b;
}data;

void signal_handler(int signo){
    printf("%f, %f\n",data.a, data.b);
    alarm(1);
}

int main()
{

    struct sigation sa;
    struct struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};
    
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = signal_handler;
    if()

    return 0;
}
