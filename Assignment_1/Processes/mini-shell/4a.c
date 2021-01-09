#include "4a.h"
void mshell()
{
int val,st;
char str[100];;
printf("enter the command");
scanf("%[^\n]s",str);
val=fork();
if(val<0)
{
perror("child process not created");
exit(1);
}
if(val==0)
{
execlp("sh","sh","-c",str,NULL);
}
else
{
waitpid(val, &st,0);
}
exit(0);
}
