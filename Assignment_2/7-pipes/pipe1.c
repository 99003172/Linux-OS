#include "pipe_header.h"

void main() 
{
    int fd1;
    fd1 = mkfifo("pipe1",0666);
    if(fd1<0)
        printf("\npipe1 is not created");
    else
        printf("\npipe1 created");
    int fd2;
    fd2 = mkfifo("pipe2",0666);
    if(fd2<0)
        printf("\npipe2 is not created");
    else
        printf("\npipe2 is created\n");
}
