/***********************************************************
* UNP.c this is used for all the network program
* which wrap all the common network function with
* a error detect and process 
* by Lian Wen on March 12, 1998 
************************************************************/
#include "unp.h"
void Close(int field)
{
	if(close(field)<0)
	{
		perror("write error ");
		exit(1);
	}
}
ssize_t Write(int field, void *buff,int p_len)
{
	ssize_t p_tmp;
	if((p_tmp=write(field,buff,p_len))<0)
	{
		perror("write error ");
		exit(1);
	}
	return p_tmp;
}

int Accept(int socket, SA *address, int *address_len)
{
	int p_id;
	if((p_id=accept(socket, address, address_len))<0)
	{
		perror("accept error ");
		exit(1);
	}	
	return p_id;
}
void Listen(int sockfd, int backlog)
{
	if(listen(sockfd,backlog)<0)
	{
		perror("listen error ");
		exit(1);
	}
}

int Socket(int family, int type, int protocol)
{
	int sockfd;
	if((sockfd=socket(family,type,protocol))<0 )
	{
		perror ("socket failed"); exit(1);
	}
	return sockfd;
}
unsigned long Inet_addr(char *p_address)
{
	struct hostent *p_tmp;
	unsigned long p_addr;
	int p_pos;
	if((p_addr=inet_addr(p_address))==0)
	{
		perror("inet_pton error for ");
		exit(1);
	}
	if((long)p_addr==-1)
	{
		p_pos=strlen(p_address);
		if(p_address[p_pos-1]==0x0a)
			p_address[p_pos-1]=0;
		p_tmp=Gethostbyname(p_address);
		p_addr=*(unsigned long *)(p_tmp->h_addr);
	}
	return p_addr;
}


void Connect(int sockfd, SA *servaddr, int p_size)
{
	if(connect(sockfd, servaddr,p_size)<0)
	{
		perror("connect error");
		exit(1);
	}
}

void Shutdown(int sockfd,int type)
{
 	if(shutdown(sockfd,type)<0)
	{
		perror("shutdown error");
		exit(1);
	}
}

int Read(int sockfd, char *recvline, int p_maxnum)
{
	int n;
	n=read(sockfd,recvline,p_maxnum);
	if(n>=0)
	{
		recvline[n]=0;
	}
	else
	{
		perror("read error");
		exit(1);
	}
	return n;
}

void Fputs(char *recvline,FILE *f)
{
	if(fputs(recvline,f)==EOF)
	{
		perror("fouts error");
		exit(1);
	}
}

void Bind(int sockfd, SA *servaddr, int p_size)
{
	if(bind(sockfd, servaddr,p_size)<0)
	{
		perror("bind error");
		exit(1);
	}
}

struct hostent *Gethostbyname(const char *hostname)
{
	struct hostent *p_tmp;
	if((p_tmp=gethostbyname(hostname))==NULL)
	{
		perror("gethostbyname error:");
		exit(1);
	}
	return p_tmp;
}	

struct hostent *Gethostbyaddr(const char *addr, size_t len,int family)
{
	struct hostent *p_tmp;
	if((p_tmp=gethostbyaddr(addr,len,family))==NULL)
	{
		perror("gethostbyaddr error:");
		exit(1);
	}
	return p_tmp;
}
struct servent *Getservbyname(const char *servname,const char *protoname)
{
	struct servent *p_tmp;
	if((p_tmp=getservbyname(servname,protoname))==NULL)
	{
		perror("getservbyname error:");
		exit(1);
	}
	return p_tmp;
}
ssize_t writen(int fd,const void *vptr,size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr=vptr;
	nleft=n;
	while(nleft>0)
	{
		if((nwritten=write(fd,ptr,nleft))<=0)
		{
			perror("writen error:");
			return 0;
/*			exit(1); */
		}
		nleft-=nwritten;
		ptr+=nwritten;
	}
	return(n);
}
ssize_t Writen(int fd,const void *vptr,size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr=vptr;
	nleft=n;
	while(nleft>0)
	{
		if((nwritten=write(fd,ptr,nleft))<=0)
		{
			perror("writen error:");
			return 0;
			exit(1); 
		}
		nleft-=nwritten;
		ptr+=nwritten;
	}
	return(n);
}

ssize_t readn(int fd, void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr=vptr;
	nleft=n;
	while(nleft>0)
	{
		if((nread=read(fd,ptr,nleft))<0)
		{
			return -1;
		}
		else if(nread==0)
		{
			break; /*EOF */
		}
		nleft-=nread;
		ptr +=nread;
	}
	return (n-nleft);
}
