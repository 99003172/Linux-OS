
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes,wd;
	fd=open("sample.txt",O_RDONLY);
	wd=open("output.txt", O_WDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=50;
	char buf[maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	write(wd,buf,nbytes);
	close(fd);
	close(wd);
	return 0;	//exit(0);
}
