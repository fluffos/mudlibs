/********************************************************
* ms.c
* the assistant program for message center 
*********************************************************/
#include "ms.h"
#include "unp.h"

void init_rec(struct recclient* rc)
{
	bzero(rc,sizeof(struct recclient));
}

void init_dis(struct disclient* dc)
{
	bzero(dc,sizeof(struct disclient));
}
void init_cmd(struct disclient* cc)
{
	bzero(cc,sizeof(struct cmdclient));
}

int ser_socket(int p_port,int *real_port)
{
	int p_fd;
	int testtime=0;
	struct sockaddr_in seradd;

	p_fd=Socket(PF_INET,SOCK_STREAM,0);
	bzero(&seradd,sizeof(seradd));
	seradd.sin_family=AF_INET;
	seradd.sin_addr.s_addr=htonl(INADDR_ANY);
	seradd.sin_port=htons(p_port);

	while((bind(p_fd,(SA *)&seradd,sizeof(seradd))<0)&&(testtime<PORTRANGE))
	{	p_port++;
		seradd.sin_port=htons(p_port);
		testtime++;
	}
	if(testtime==PORTRANGE)
	{
		printf("no free port\n");
		exit(1);
	}
	Listen(p_fd,LISTENQ);
	*real_port=p_port;
	return p_fd;
}

int cli_socket(char *p_address,int p_port,int *real_port)
{
	int p_fd;
	int testtime=0;
	struct sockaddr_in seradd;

	p_fd=Socket(PF_INET,SOCK_STREAM,0);
	bzero(&seradd,sizeof(seradd));
	seradd.sin_family=AF_INET;

	seradd.sin_addr.s_addr=Inet_addr(p_address);
	
	seradd.sin_port=htons(p_port);

	while((connect(p_fd,(SA *)&seradd,sizeof(seradd))<0)&&(testtime<PORTRANGE))
	{	p_port++;
		printf("try port %d\n",p_port);
		testtime++;
		p_fd=Socket(PF_INET,SOCK_STREAM,0);
		bzero(&seradd,sizeof(seradd));
		seradd.sin_family=AF_INET;

		seradd.sin_addr.s_addr=Inet_addr(p_address);
	
		seradd.sin_port=htons(p_port);
	}
	if(testtime==PORTRANGE)
	{
		printf("can not find the server\n");
		exit(1);
	}
	*real_port=p_port;
	return p_fd;
}


int cmd_para(char *input,int len,char *cmd,char *para1,char *para2,char *para3)
{
	int i=0;
	int p_part=0;
	int p_curp=0;
	int p_point=0;
	int p_getit=0;
	char p_char;
	cmd[0]=0;
	para1[0]=0;
	para2[0]=0;
	para3[0]=0;
	while(p_point<len)
	{
		p_char=input[p_point++];
		if((p_char==' ')&&(p_part<3))
		{
			p_curp=0;
			p_part++;
		}
		else if(p_char=='\n')
		{
			p_getit=1;
			break;
		}
		else if(p_char==0x0d)
		{
			p_getit=1;
			p_point++; // suppose that is 0a next
			break;
		}

		else
		{
			switch(p_part)
			{
			case 0: 
				cmd[p_curp++]=p_char;
				cmd[p_curp]=0;
				break;
			case 1:
				para1[p_curp++]=p_char;
				para1[p_curp]=0;
				break;
			case 2:
				para2[p_curp++]=p_char;
				para2[p_curp]=0;
				break;
			case 3:
				para3[p_curp++]=p_char;
				para3[p_curp]=0;
				break;
			}
		}
		if (p_curp>=(PARMAX-1)) /* at leaset one part it too long */
		{
			strcpy(cmd,"wrong");
			para1[0]=0;
			para2[0]=0;
			para3[0]=0;
			return 0; /* all buff will be useless */
		}
	}
	if(p_getit) /* get a return */
	{
		for(i=p_point;i<len;++i)
			input[i]=input[i+p_point];
		return (len-p_point);
	}
	return len; /* means can't find return and mistake*/
}
void cmd_help(int p_fd)
{
	int f_fd;
	int count;
	char p_buf[100];
	f_fd=open("help.txt",O_RDONLY);
	while((count=read(f_fd,p_buf,100))>0)
		writen(p_fd,p_buf,count);
	strcpy(p_buf,M_NEWLINE);
	writen(p_fd,p_buf,strlen(p_buf));
	return;
}

int pass_verify(char *name,char *pass)
{
	if((strcmp(name,"test")==0)
		&&(strcmp(pass,"ok")==0))
		return 1;
	if((strcmp(name,"itb542")==0)
		&&(strcmp(pass,"sesame")==0))
		return 1;
	return 0;
}
unsigned long messwrap(char* input,char* output,unsigned long len)
{
	int i;
	char *p_lenchar;
	unsigned long p_len;
	p_len=htonl(len);
	p_lenchar=(char *)&p_len;
	for(i=0;i<4;++i)
		output[i]=*(p_lenchar++);
	for(i=0;i<len;++i)
		output[i+4]=input[i];
	return len+4;
}

