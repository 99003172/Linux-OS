#include "copy_header.h"

int copyfile()
{
	int fd,nbytes,wd;
	fd=open("sample.txt",O_RDONLY,0666);
	wd=open("out.txt", O_WRONLY|O_CREAT,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=100;
	char buf[maxlen];
	read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	write(wd,buf,strlen(buf));
	close(fd);
	close(wd);
	return 0;	//exit(0);
}
