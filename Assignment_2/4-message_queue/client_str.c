#include "server_client_mq.h"

int main()
{
	int ret, nbytes;
	mqd_t mqid;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	
	/* Open a Message Queue in Client Process */
	
	mqid = mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char str[20] = "HelloLTTS";
	/* Send a message to Queue */
	ret = mq_send(mqid,str,20,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}

	char buf[8192];
	int maxlen=256,prio;
	
	/* Receive the message from Server through Queue */
	
	nbytes = mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("msg from server : %s\n",buf);
	
	/* Close the Queue */
	
	mq_close(mqid);

	return 0;
}