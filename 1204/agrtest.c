#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 4

#define WORK_PER_THREAD 100

struct thread_args{
    int myid;
    long long start;
    long long end;
};

volatile long long sum[NUM_THREADS];

void *myfunc(void *arg)
{
    struct thread_args *agru = (struct thread_args *)arg;
    sum[agru->myid] = agru->start + agru->end;
    printf("myid : %d, start : %lld, end : %lld\n",agru->myid, agru->start, agru->end);
    pthread_exit(NULL);
}

int main()
{
    pthread_t mythread[NUM_THREADS];
    struct thread_args range[NUM_THREADS];
    int result;
   // result = pthread_create(&mythread,NULL,myfunc,range);
    
    /*if(result){
        perror("pthread_create");
        exit(1);
    }*/
    
    
    printf("I am a main thread\n");

    for(int i = 0; i <  NUM_THREADS; i++)
    {
        range[i].myid = i;
        range[i].start = i*WORK_PER_THREAD+1;
        range[i].end = (1+i)*WORK_PER_THREAD;
        result = pthread_create(&mythread[i], NULL,myfunc,&range[i]);
        if(result){
            perror("pthread_create");
            exit(1);
        }
    }
    
    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(mythread[i],NULL);
        printf("sum[i] is : %lld\n",sum[i]);
    }
 
   // pthread_join(mythread,NULL);
}
