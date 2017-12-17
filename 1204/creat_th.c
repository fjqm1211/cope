#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile char running= 1;
volatile long long counter = 0;

void *myfunc(void *arg)
{
    while(running)
    {
        counter++;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t mythread;
    int result;
    result = pthread_create(&mythread,NULL,myfunc,NULL);
    
    if(result){
        perror("pthread_create");
        exit(1);
    }
    
    
    printf("I am a main thread\n");

    for(int i = 0; i < 30; i++)
    {
        printf("counter is %lld\n",counter);
        sleep(1);
    }
    running = 0;

    pthread_join(mythread,NULL);
}
