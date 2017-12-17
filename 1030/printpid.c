#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
 printf("PID is %ld\n",(long)getpid());
 printf("PPID is %ld\n",(long)getppid());
}
