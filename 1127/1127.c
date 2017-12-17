#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void func_a()
{
    printf("hello my pid = %ld\n",(long)getpid());
    sleep(1);
}

void func_b()
{
    func_a();
}

void func_c()
{
    func_b();
}

int main()
{
    while(1)
    {
        func_c();
    }

    return 0;
}
