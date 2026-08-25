/******************************************************
* file name discli.c
* this is the main program for client which display
* the message sent to the message center 
*******************************************************/
#include "unp.h"
#include "ms.h"

void doclnt(int sockfd);

void main()
{
	char p_address[51];
	u_short p_port;
	int p_tmp;
	int sockfd,n;
	char recvline[MAXLINE+1];
	struct sockaddr_in servaddr;
	printf("Message Center message display client.\n");
	printf("Trying to connect . . . .\n");
	strcpy(p_address,"127.0.0.1");
	p_port=DISPORT;


	sockfd=cli_socket(p_address,p_port,&p_tmp);
	printf("Connected ! ! ! \n\n");

	doclnt(sockfd);
	exit(0);
}

void doclnt(int sockfd)
{
	int len,maxfdp1;
	fd_set readset;
	char buffer[1024];
	unsigned long p_bytes; // this identify the length of bytes follows

	FD_ZERO(&readset);
	for(;;)
	{
		FD_SET(0,&readset);
		FD_SET(sockfd,&readset);
		maxfdp1=sockfd+1;
		select(maxfdp1,&readset,NULL,NULL,NULL);
		if(FD_ISSET(sockfd,&readset))
		{
			
			if((len=readn(sockfd,&p_bytes ,4))<=0)
			{
				fprintf(stdout,"Disconnected by the server\n");
				return;
			}
			p_bytes=ntohl(p_bytes);
			while(p_bytes>0)
			{
				if((len=readn(sockfd,buffer,
				min(p_bytes,sizeof(buffer))))<=0)
				{
					fprintf(stdout,"Disconnected by the server\n");
					return;
				}
				writen(1,buffer,len);
				p_bytes-=len;
			}
		}
		if(FD_ISSET(0,&readset))
		{
			if((len=read(0,buffer,sizeof(buffer)))<=0)
			{	
				Close(sockfd);
				return;  
			}
		}
	}
}