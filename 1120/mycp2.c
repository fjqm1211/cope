#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 100

int main(int argc,char *argv[]){
    int fd_r, fd_w;
    char *buf[BUFFSIZE];
    int s;
    struct stat statbuf;

    fd_r = open(argv[1],O_RDONLY);

    fd_w = open(argv[2],O_WRONLY | O_CREAT,0666);

    while((s = read(fd_r,buf,100)) > 0){
        write(fd_w,buf,s);
    }

    stat(argv[1],&statbuf);
    chmod(argv[2],statbuf.st_mode);

    close(fd_r);
    close(fd_w);

    return 0;
}
