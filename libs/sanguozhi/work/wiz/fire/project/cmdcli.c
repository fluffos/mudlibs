/*****************************************************************
* file name cmdcli.c
* this is the main program for client which give command to
* the message center 
******************************************************************/
#include "unp.h"
#include "ms.h"
void doclnt(int sockfd);

void main(int argc, char *argv[])
{
	char p_address[51];
	u_short p_port;
	int p_tmp;
	int sockfd,n;
	char recvline[MAXLINE+1];
	if(argc>1)
	{
		strcpy(p_address,argv[1]);
	}
	else
	{
		printf("Please input the IP address or Host name :\n");
		p_tmp=read(0,p_address,50);
		p_address[p_tmp]=0;
	}
	printf("Message Center Command Client.\n");
	printf("Connecting . . . . .\n");

	sockfd=cli_socket(p_address,CMDPORT,&p_tmp);

	printf("Connected ! ! !\n");
	doclnt(sockfd);
	exit(0);
}

void doclnt(int sockfd)
{
	int len,maxfdp1;
	fd_set readset;
	char buffer[1024];

	FD_ZERO(&readset);
	for(;;)
	{
		FD_SET(0,&readset);
		FD_SET(sockfd,&readset);
		maxfdp1=sockfd+1;
		select(maxfdp1,&readset,NULL,NULL,NULL);
		if(FD_ISSET(sockfd,&readset))
		{
			if((len=read(sockfd,buffer,sizeof(buffer)))<=0)
			{
				fprintf(stdout,"Sever disconnected the connection !\n");
				return;
			}
			else
				writen(1,buffer,len);
		}
		if(FD_ISSET(0,&readset))
		{
			if((len=read(0,buffer,sizeof(buffer)))<=0)
			{	
				/* what should i do ?
				   discard it :-) */
			}
			else
			{
				writen(sockfd,buffer,len);
			}
		}
	}
}

