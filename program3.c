#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compile()
{
    pid_t pid=fork();
    int child_process;
    if (pid==0)
    { /* created child process */
    	child_process=execl(,NULL);
        exit(127); /* only if execlp fails */
    }
    else
    { /* pid>0; parent process */
    	waitpid(pid,0,0); /* waiting  for child to exit */
    	printf("Parent Process\n");
    }
}