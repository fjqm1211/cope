#include <sys/types.h>
#include <stat.h>
#include <fcnt1.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char *argv[] ){
    int fd;
   
     if(argc != 2){
        fprintf(stderr, "usage : opentestfilename\n");
        exit(0);
    }

    fd = open(argv[1], 0_RDONLY);
    
    if( fd == -1 ){
        perror("cope:");
        exit(0);
    }
    else{
        printf("open %s succes \n",argv[1]);
    }
}
