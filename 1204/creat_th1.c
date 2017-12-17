#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *myfunc(void *arg)
{
    printf("Hello pthread world!\n");
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

    pthread_join(mythread,NULL);
}
