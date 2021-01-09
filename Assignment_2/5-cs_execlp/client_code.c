#include "sc_header.h"

int main()
{
	int ret,nbytes2;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid3;
	/* Open a Message Queue in Client */
	mqid3=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid3<0)                                        //cannot open
	{
		perror("mq_open");
		exit(1);
	}
	char buf1[8192];
	int maxlen=256,prio;
	nbytes1=mq_receive(mqid3,buf1,maxlen,&prio);   //receive data from buffer
	if(nbytes2<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf1[nbytes2]='\0';
	int k;
    printf("%s",buf1);
	
	k=execlp("/bin/gcc","gcc",buf1,0);
    if(k<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf1,nbytes2,prio);
	mq_close(mqid3);
	return 0;
}