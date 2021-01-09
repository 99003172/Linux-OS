#include "count.h"
int num_lines, num_chars, num_words;;

int  count_func()
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
               num_lines++;
            /* to  Check words */
            if (ch[i] == ' ' || ch[i] == '\t')
               num_words++;
        }
        num_chars=nbytes;
    }
    close(fd);
	
int count_lines()
{
	return num_lines;
}
int count_words()
{
	return num_words;
}
int count_chars()
{
	return num_chars;
}


return 0;
}
