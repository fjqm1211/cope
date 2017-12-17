#include <unistd.h>

int main(int argc, char *argv[]){
    
    pid_t pid=fork();
    execl("/bin/ps","ps","-ef",NULL);
    
    switch(pid){

}
    return 0;
}
