#include "server_client_mq.h"

int main()
{
	int ret,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	/* Message Queue in Server Process */
	mqid=mq_open("/mque",O_CREAT | O_RDWR,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}

	char buffer[8192];
	int maxlen=256,priorty;
	/* Receive message from Queue */
	printf("Waiting for message from Client .......\n");
	nbytes=mq_receive(mqid,buffer,maxlen,&priorty);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[nbytes]='\0';
	printf("msg from client : %s\n",buffer);

	/* Toggle the message received */
	for (int i=0; buffer[i]!='\0'; i++)
    {
        if (buffer[i]>='A' && buffer[i]<='Z')
            buffer[i] = buffer[i] + 'a' - 'A';
        else if (buffer[i]>='a' && buffer[i]<='z')
            buffer[i] = buffer[i] + 'A' - 'a';
    }

	/* Sending back the message to Client  */
	
	ret = mq_send(mqid,buffer,100,100);
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}
	/* Close the Queue */
	mq_close(mqid);
	return 0;
}