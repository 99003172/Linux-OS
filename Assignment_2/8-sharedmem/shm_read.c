#include "shm.h"

int main()
{
	int file_size=4096; 
	int fd,offset=0;
	fd=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    ftruncate(fd, file_size);
	void *pbase;
	pbase=mmap(0,file_size, PROT_READ, MAP_SHARED,fd,offset);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"memory mapping failed\n");
		exit(1);
	}
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	char buffer[64];
	sem_wait(qs);
	sem_wait(ps);
        strncpy(buffer,pbase,10);
	printf("buffer=%s\n",buffer);
	strcpy(buffer,pbase+10);
	printf("buffer=%s\n",buffer);
	 sem_post(ps);
	sem_unlink("s1");
	sem_unlink("s2");
	munmap(pbase,file_size);
	return 0;
}
	