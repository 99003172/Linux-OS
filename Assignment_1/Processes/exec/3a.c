#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    pid_t pid=fork();
    int cp;
    if (pid==0)
    { /* creating child process */
    	cp=execlp("gcc","gcc","welcome.c","-o", "welcome.out",NULL);
        exit(1); /* only if execlp fails */
    }
    else
    { /* pid!=0; parent process */
    	waitpid(pid,0,0); /* wait for child process to exit */
    	printf("Parent Process\n");
    }
    return 0;
}
