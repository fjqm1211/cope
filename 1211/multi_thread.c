#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 8
#define WORK_PER_THREAD 1000000000 / NUM_THREADS

struct thread_args{
    int myid;
    long long start;
    long long end;
};

volatile long long sum[NUM_THREADS];

void *threads(void *arg)
{
    struct thread_args *f_arg = (struct thread_args *)arg;
    for(long long i = f_arg->start; i <= f_arg->end; i++)
        sum[f_arg->myid] += i;
    pthread_exit(NULL);
}

int main()
{
    pthread_t mythread[NUM_THREADS];
    struct thread_args info[NUM_THREADS];
    int fail; 
    long long total_sum = 0;

    for(long long i = 0; i < NUM_THREADS; i++)
    {
        info[i].myid = i;
        info[i].start = (i * WORK_PER_THREAD) + 1;
        info[i].end = (i+1) * WORK_PER_THREAD;

        fail = pthread_create(&mythread[i],NULL,threads, (void *)&info[i]);
        if(fail)
        {
            perror("pthread_create");
            exit(0);
        }
    }
    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(mythread[i], NULL);
        printf("%ith sum : %lld\n", i, sum[i]);
        total_sum += sum[i];
    }
    printf("total sum = %lld\n", total_sum);

    return 0;

}
