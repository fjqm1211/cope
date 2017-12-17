#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_system(char *command)
{
    pid_t fork(void);
    execl("/bin/sh","sh","-c",command,(char *) 0);
}

int main(void)
{
    int status;
    status = my_system("ls -l | wc");
    printf("exit code %d\n", WEXITSTATUS(status));

    return 0;
}
