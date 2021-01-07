#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num_lines, num_chars, num_words;;

int  checkfile()
{
	int fd,nbytes;
	char ch[1000];
  fd=open("sample.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
  num_words = 0,num_lines = 0;
    while(nbytes=read(fd,ch,sizeof(ch)))
    {
        for(int i=0;i<nbytes;i++)
        {
            /* to Check new line */
            if (ch[i] == '\n')
               lines++;
            /* to  Check words */
            if (ch[i] == ' ' || ch[i] == '\t')
               words++;
        }
        num_chars=nbytes;
    }
    close(fd);
printf("\n number of charcters is %d",num_chars);
printf("\n number of words is %d", num_words);
printf("\n number of lines is %d",num_lines);
return 0;
}
