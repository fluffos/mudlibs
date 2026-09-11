/********************************************************
* the messser.c
* this is the main program of this message center
* this is the main program of the server. 
*********************************************************/
#include "unp.h"
#include "ms.h"

int fd_set_rec(fd_set *read_set);
int fd_set_dis(fd_set *read_set);
int new_rec_connection();
int new_dis_connection();
void init();
int get_rec_id(	fd_set* read_set);
int get_dis_id(	fd_set* read_set);
int rec_mess(int rec_id);
void dis_mess(int p_id);

int cmd_rec(int p_id);

struct recclient rc[MAXREC];
struct disclient dc[MAXDIS];
struct cmdclient cc[MAXCMD];

int reclistenfd;
int dislistenfd;
int cmdlistenfd;
int cmd_port,dis_port,rec_port;
unsigned long *locaddr;  /* this is used to store loc address */

void main()
{
	int i;
	fd_set read_set;
	int maxfdp;
	int p_tmp;
	int p_id;
	init();
	printf("The cmd port is %d, rec port is %d and dis port is %d\n",
		cmd_port,rec_port,dis_port);
	for(;;)
	{
		FD_ZERO(&read_set);
		FD_SET(reclistenfd,&read_set);
		FD_SET(dislistenfd,&read_set);
		FD_SET(cmdlistenfd,&read_set);
		maxfdp=max(reclistenfd,dislistenfd);
		maxfdp=max(maxfdp,cmdlistenfd);

		p_tmp=fd_set_rec(&read_set);
		maxfdp=max(p_tmp,maxfdp);
		
		p_tmp=fd_set_dis(&read_set);
		maxfdp=max(p_tmp,maxfdp);

		p_tmp=fd_set_cmd(&read_set);
		maxfdp=max(p_tmp,maxfdp);
		
		maxfdp=maxfdp+1;

		select(maxfdp,&read_set,NULL,NULL,NULL);
		if(FD_ISSET(reclistenfd,&read_set)) /* new receive connection */
		{
			new_rec_connection();
		}
		if(FD_ISSET(dislistenfd,&read_set)) /* new display connection */
		{
			new_dis_connection();
		}
		if(FD_ISSET(cmdlistenfd,&read_set)) /* new command connection */
		{
			new_cmd_connection();
		}

		p_id=get_rec_id(&read_set);
		if(p_id!=-1) /* -1 means no rec mess */
		{
			if(rec_mess(p_id))
			{
				dis_mess(p_id);
			} 
		}
		p_id=get_dis_id(&read_set);
		if(p_id!=-1) /* -1 means no dis mess */
		{/* this is mainly used to judge if some disp connection is over */
			dis_test(p_id);
		}
		p_id=get_cmd_id(&read_set);
		if(p_id!=-1)
		{
			cmd_rec(p_id);
		}

	}
}
/* this program is used to read from the receive port */
int rec_mess(int rec_id)
{
	int p_bytes;
	p_bytes=read(rc[rec_id].r_fd,rc[rec_id].r_messbuf,MAXBUFFSIZE);
	if(p_bytes<=0)
	{
		Close(rc[rec_id].r_fd);
		init_rec( &rc[rec_id]);
		return 0;
	}
	rc[rec_id].r_bytes=p_bytes;
	rc[rec_id].r_tbytes=rc[rec_id].r_tbytes+p_bytes;
	rc[rec_id].r_rectime=time(NULL);
/*	printf("%d bytes readed\n",p_bytes); */
	return p_bytes;
}
int dis_test(int dis_id)
{
	int p_bytes;
	char p_tmp[MAXBUFFSIZE];
	p_bytes=read(dc[dis_id].d_fd,p_tmp,MAXBUFFSIZE);
	if(p_bytes<=0)
	{
		Close(dc[dis_id].d_fd);
/*		printf("close dis conn\n"); */
		init_dis( &dc[dis_id]);
		return 0;
	}
	return p_bytes;
}
int get_rec_id(	fd_set* read_set)
{
	int i;

	for(i=0;i<MAXREC;++i)
	{
		if((rc[i].r_fd)&&(FD_ISSET(rc[i].r_fd,read_set)))
		{
			return i;	
		}
	}
	return -1;
}
int get_cmd_id(	fd_set* read_set)
{
	int i;

	for(i=0;i<MAXCMD;++i)
	{
		if((cc[i].c_fd)&&(FD_ISSET(cc[i].c_fd,read_set)))
		{
			return i;	
		}
	}
	return -1;
}
int get_dis_id(	fd_set* read_set)
{
	int i;

	for(i=0;i<MAXDIS;++i)
	{
		if((dc[i].d_fd)&&(FD_ISSET(dc[i].d_fd,read_set)))
		{
			return i;	
		}
	}
	return -1;
}

int new_rec_connection() /* return 1 means con 0 means refuse */
{
	int confd;
	int p_len;
	int p_con=0;
	int i;
	struct sockaddr_in p_addr;
	p_len=sizeof(p_addr);
	confd=Accept(reclistenfd,(SA *)&p_addr,&p_len);
	for(i=0;i<MAXREC;++i)
	{
		if(rc[i].r_fd==0)
		{
			rc[i].r_fd=confd;
			rc[i].r_add=ntohl(p_addr.sin_addr.s_addr);
			rc[i].r_port=ntohs(p_addr.sin_port);
			rc[i].r_contime=time(NULL);
			p_con=1;
			break;
		}
	}
	if(!p_con)
		close(confd);
	return p_con;
}
int new_cmd_connection() /* return 1 means con 0 means refuse */
{
	int confd;
	int p_len;
	int p_con=0;
	int i;
	struct sockaddr_in p_addr;
	char p_buf[80];
	p_len=sizeof(p_addr);
	confd=Accept(cmdlistenfd,(SA *)&p_addr,&p_len);
	for(i=0;i<MAXCMD;++i)
	{
		if(cc[i].c_fd==0)
		{
			cc[i].c_fd=confd;
			cc[i].c_add=ntohl(p_addr.sin_addr.s_addr);
			cc[i].c_port=ntohs(p_addr.sin_port);
			cc[i].c_contime=time(NULL);
			cc[i].c_stat=0; /* wait for user */
			strcpy(p_buf,M_WELCOME);
			writen(cc[i].c_fd,p_buf,strlen(p_buf));
			strcpy(p_buf,M_HELPTITLE);
			writen(cc[i].c_fd,p_buf,strlen(p_buf));
			strcpy(p_buf,M_PROM2);
			writen(cc[i].c_fd,p_buf,strlen(p_buf)-1);
			p_con=1;
			break;
		}
	}
	if(!p_con)
	{
		strcpy(p_buf,M_NOCONN);
		writen(confd,p_buf,strlen(p_buf));
		close(confd);
	}
	return p_con;
}

int new_dis_connection() /* return 1 means con 0 means refuse */
{
	int confd;
	int p_len;
	int p_con=0;
	int i;
	struct sockaddr_in p_addr;
	p_len=sizeof(p_addr);
	confd=Accept(dislistenfd,(SA *)&p_addr,&p_len);

	
	for(i=0;i<MAXDIS;++i)
	{
		if(dc[i].d_fd==0)
		{
			dc[i].d_fd=confd;
			dc[i].d_add=ntohl(p_addr.sin_addr.s_addr);
			dc[i].d_port=ntohs(p_addr.sin_port);
			dc[i].d_contime=time(NULL);
			p_con=1;
			break;
		}
	}
	if(!p_con)
		close(confd);
	return p_con;
}

int fd_set_rec(fd_set *read_set)
{
	int p_max=0;
	int i;
	for(i=0;i<MAXREC;++i)
	{
		if(rc[i].r_fd)
		{
			p_max=max(p_max,rc[i].r_fd);
			FD_SET(rc[i].r_fd,read_set);
		}
	}
	return p_max;
}




int fd_set_dis(fd_set *read_set)
{
	int p_max=0;
	int i;
	for(i=0;i<MAXDIS;++i)
	{
		if(dc[i].d_fd)
		{
			p_max=max(p_max,dc[i].d_fd);
			FD_SET(dc[i].d_fd,read_set);
		}
	}
	return p_max;
}

int fd_set_cmd(fd_set *read_set)
{
	int p_max=0;
	int i;
	for(i=0;i<MAXCMD;++i)
	{
		if(cc[i].c_fd)
		{
			p_max=max(p_max,cc[i].c_fd);
			FD_SET(cc[i].c_fd,read_set);
		}
	}
	return p_max;
}

void init()
{
	struct sockaddr_in seradd;
	int i;
	for(i=0;i<MAXREC;++i)
		init_rec(&rc[i]);
	for(i=0;i<MAXDIS;++i)
		init_dis(&dc[i]);
	for(i=0;i<MAXCMD;++i)
		init_cmd(&cc[i]);
	reclistenfd=ser_socket(RECPORT,&rec_port);
	dislistenfd=ser_socket(DISPORT,&dis_port);

	cmdlistenfd=ser_socket(CMDPORT,&cmd_port);

}
/* this program is used to display mess to mess port */
void dis_mess(int p_id)
{
	char p_title[100];
	char p_newtitle[104];
	char p_tmpbuf[MAXBUFFSIZE+4];
	int i;
	unsigned long p_titlelen,p_messlen;
//	p_titlelen=messwrap(p_title,p_newtitle,(unsigned long)strlen(p_title));
	p_messlen=messwrap(rc[p_id].r_messbuf,p_tmpbuf,rc[p_id].r_bytes);
	for(i=0;i<MAXDIS;++i)
	{
		if(dc[i].d_fd)
		{
//			writen(dc[i].d_fd,p_newtitle,p_titlelen);
			writen(dc[i].d_fd,p_tmpbuf,p_messlen);
		}
	}
}
/* this is used to hold the receive cmd */
int cmd_rec(int p_id)
{
	int p_bytes,p_newpoint;
	char p_cmd[PARMAX],p_para1[PARMAX],p_para2[PARMAX],p_para3[PARMAX];
	char p_buf[200];
	p_bytes=read(cc[p_id].c_fd,
		&(cc[p_id].c_cmd[cc[p_id].c_cmdpoint])
		,MAXCMD2-cc[p_id].c_cmdpoint);
	
	if(p_bytes<=0)
	{
		Close(cc[p_id].c_fd);
		init_cmd( &cc[p_id]);
		return 0;
	}

	cc[p_id].c_cmdpoint+=p_bytes;
	p_newpoint=cmd_para(cc[p_id].c_cmd,
		cc[p_id].c_cmdpoint,p_cmd,p_para1,p_para2,p_para3);
	if(cc[p_id].c_cmdpoint==p_newpoint) /* not get a full line */
	{
		return 0;
	}
	if(cmd_do(p_id,p_cmd,p_para1,p_para2,p_para3)==-1)/* quit */
	{
		Close(cc[p_id].c_fd);
		init_cmd(&cc[p_id]);		
		return 0;
	}

	
	cc[p_id].c_cmdpoint=p_newpoint;

	if(cc[p_id].c_stat==3)
		strcpy(p_buf,M_PROM);	
	else
		strcpy(p_buf,M_PROM2);	
	writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
	return p_bytes;
}
int cmd_do(int p_id,char* p_cmd,char* p_para1,char* p_para2,char* p_para3)
{
	int p_fd,p_tmp;
	char p_buf[100];
	p_fd=cc[p_id].c_fd;
	
	if(strcmp(p_cmd,"")==0)
		return 0;
	if(strcmp(p_cmd,"help")==0)
	{
		cmd_help(p_fd);
		return 0;
	}
	if(strcmp(p_cmd,"quit")==0)
	{
		return -1;
	}
	if(strcmp(p_cmd,"user")==0)
	{
		if((strlen(p_para1)>0)&&(strlen(p_para1)<10))
		{
			strcpy(cc[p_id].c_name,p_para1);
			cc[p_id].c_stat=1;
			strcpy(p_buf,M_WAITPASS);
			writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
			return 0;
		}
	}
	if(strcmp(p_cmd,"pass")==0)
	{
		if((strlen(p_para1)>0)&&(strlen(p_para1)<10))
		{
			switch(cc[p_id].c_stat)
			{
			case 0:
				strcpy(p_buf,M_WAITLOG);
				break;
			case 1:
				strcpy(cc[p_id].c_pass,p_para1);
				if(pass_verify(cc[p_id].c_name,
					cc[p_id].c_pass))
				{
					cc[p_id].c_stat=3;
					strcpy(p_buf,M_PASSCORRECT);
				}
				else
				{
					strcpy(p_buf,M_PASSWRONG);
				}
				break;
			default:
				strcpy(p_buf,M_NOPASSNEED);
				break;
			}
			writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
			return 0;
		}
	}
	if((strcmp(p_cmd,"client")==0)&&
		(strcmp(p_para1,"list")==0))
	{
		switch(cc[p_id].c_stat)
		{
		case 0:
			strcpy(p_buf,M_WAITLOG);
			break;
		case 1:
			strcpy(p_buf,M_WAITPASS);
			break;
		default:
			cmd_list_client(p_fd);
			return 0;
		}
		writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
		return 0;
	}
	if((strcmp(p_cmd,"message")==0)&&
		(strcmp(p_para1,"list")==0))
	{
		switch(cc[p_id].c_stat)
		{
		case 0:
			strcpy(p_buf,M_WAITLOG);
			break;
		case 1:
			strcpy(p_buf,M_WAITPASS);
			break;
		default:
			cmd_list_message(p_fd);
			return 0;
		}
		writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
		return 0;
	}

	if((strcmp(p_cmd,"shutdown")==0)&&
		(strcmp(p_para1,cc[p_id].c_pass)==0)&&(strlen(p_para1)))
	{
		switch(cc[p_id].c_stat)
		{
		case 0:
			strcpy(p_buf,M_WAITLOG);
			break;
		case 1:
			strcpy(p_buf,M_WAITPASS);
			break;
		default:
			exit(0);
		}
		writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
		return 0;
	}

	if((strcmp(p_cmd,"client")==0)&&
		(strcmp(p_para1,"delete")==0))
	{
		switch(cc[p_id].c_stat)
		{
		case 0:
			strcpy(p_buf,M_WAITLOG);
			break;
		case 1:
			strcpy(p_buf,M_WAITPASS);
			break;
		default:
			p_tmp=cmd_delete_client(p_fd,p_para2,p_para3);
			switch(p_tmp)
			{
				case 0: // succ
					strcpy(p_buf,M_DELETECLIENTSUCC);	
					break;
				case 1: // no such client
					strcpy(p_buf,M_NOSUCHCLIENT);	
					break;
				case 2: // para wrong
					strcpy(p_buf,M_UNKNOWCMD);
					writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
					strcpy(p_buf,M_HELPTITLE);
					writen(cc[p_id].c_fd,p_buf,strlen(p_buf)); 
					strcpy(p_buf,M_NEWLINE);
					break;
				default : // dele one self
					strcpy(p_buf,M_DELETESELF);
					break;
			}
		}
		writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
		return 0;
	}




	if((strcmp(p_cmd,"message")==0)&&
		(strcmp(p_para1,"delete")==0))
	{
		switch(cc[p_id].c_stat)
		{
		case 0:
			strcpy(p_buf,M_WAITLOG);
			break;
		case 1:
			strcpy(p_buf,M_WAITPASS);
			break;
		default:
			p_tmp=cmd_delete_message(p_para2,p_para3);
			switch(p_tmp)
			{
				case 0: // succ
					strcpy(p_buf,M_DELETEMESSAGESUCC);	
					break;
				case 1: // no such client
					strcpy(p_buf,M_NOSUCHMESSAGE);	
					break;
				case 2: // para wrong
					strcpy(p_buf,M_UNKNOWCMD);
					writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
					strcpy(p_buf,M_HELPTITLE);
					writen(cc[p_id].c_fd,p_buf,strlen(p_buf)); 
					strcpy(p_buf,M_NEWLINE);
					break;
			}
		}
		writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
		return 0;
	}


	strcpy(p_buf,M_UNKNOWCMD);
	writen(cc[p_id].c_fd,p_buf,strlen(p_buf));
	strcpy(p_buf,M_HELPTITLE);
	writen(cc[p_id].c_fd,p_buf,strlen(p_buf)); 
	strcpy(p_buf,M_NEWLINE);
	writen(cc[p_id].c_fd,p_buf,strlen(p_buf)); 
	return 0;
}
void cmd_list_client(int p_fd)
{
	char p_buf[200];
	int i;
	sprintf(p_buf,"The cmd port is %d The dis port is %d and the rec port is %d\n",
		cmd_port,dis_port,rec_port);
	writen(p_fd,p_buf,strlen(p_buf));
	strcpy(p_buf,M_CLIENTLISTTITLE);
	writen(p_fd,p_buf,strlen(p_buf)); 

	strcpy(p_buf,M_MESSBAR);
	writen(p_fd,p_buf,strlen(p_buf)); 

	strcpy(p_buf,M_CLIENTLISTTITLE2);
	writen(p_fd,p_buf,strlen(p_buf)); 

	strcpy(p_buf,M_MESSBAR2);
	writen(p_fd,p_buf,strlen(p_buf)); 

	for(i=0;i<MAXREC;++i)
	{
		if(rc[i].r_fd)
		{
                sprintf(p_buf,"    Message_rec    %2d       %4d   %.24s\n",
                        rc[i].r_fd,
//                        inet_ntoa(htonl(rc[i].r_add)),
			rc[i].r_port,
			ctime(&rc[i].r_contime));
		writen(p_fd,p_buf,strlen(p_buf)); 
		}
	}  // this part used to display client of message_receive port
	for(i=0;i<MAXDIS;++i)
	{
		if(dc[i].d_fd)
		{
		sprintf(p_buf,"    Message_dis    %2d    %15s   %4d   %.24s\n",
			dc[i].d_fd,
			inet_ntoa(htonl(dc[i].d_add)),
			dc[i].d_port,
			ctime(&dc[i].d_contime));
		writen(p_fd,p_buf,strlen(p_buf)); 
		}
	}
		
	for(i=0;i<MAXCMD;++i)
	{
		if(cc[i].c_fd)
		{
		int itmp;
		char ctmp[100];
		strcpy(ctmp,"test sprintf\n");
		writen(p_fd,ctmp,strlen(ctmp));
		sprintf(p_buf,"    Message_cmd    %2d       %4d   %.24s\n",
			cc[i].c_fd,
//			inet_ntoa(htonl(cc[i].c_add)),
			cc[i].c_port,
			ctime(&cc[i].c_contime));

		strcpy(ctmp,"after sprintf before strlen\n");
		writen(p_fd,ctmp,strlen(ctmp));

		itmp=strlen(p_buf);

		strcpy(ctmp,"after strlen before writen\n");
		writen(p_fd,ctmp,strlen(ctmp));

		writen(p_fd,p_buf,strlen(p_buf)); 

		strcpy(ctmp,"after writen\n");
		writen(p_fd,ctmp,strlen(ctmp));
		}
	}  // this part used to display client of command control port
	strcpy(p_buf,M_MESSBAR);
	writen(p_fd,p_buf,strlen(p_buf)); 
	strcpy(p_buf,M_NEWLINE);
	writen(p_fd,p_buf,strlen(p_buf)); 
}
void cmd_list_message(int p_fd)
{
	char p_buf[100];
	int i;
	strcpy(p_buf,M_MESSAGELISTTITLE);
	writen(p_fd,p_buf,strlen(p_buf)); 

	strcpy(p_buf,M_MESSBAR);
	writen(p_fd,p_buf,strlen(p_buf)); 

	strcpy(p_buf,M_MESSAGELISTTITLE2);
	writen(p_fd,p_buf,strlen(p_buf)); 

	strcpy(p_buf,M_MESSBAR2);
	writen(p_fd,p_buf,strlen(p_buf)); 

	for(i=0;i<MAXREC;++i)
	{
		if((rc[i].r_fd)&&(rc[i].r_bytes))
		{
		sprintf(p_buf,"    %5d          %2d    %15s   %4d   %.24s\n",
			rc[i].r_bytes,
			rc[i].r_fd,
			inet_ntoa(htonl(rc[i].r_add)),
			rc[i].r_port,
			ctime(&rc[i].r_contime)); // it's better to use r_rectime
		writen(p_fd,p_buf,strlen(p_buf)); 
		}
	}
	strcpy(p_buf,M_MESSBAR);
	writen(p_fd,p_buf,strlen(p_buf)); 
	strcpy(p_buf,M_NEWLINE);
	writen(p_fd,p_buf,strlen(p_buf)); 
}

int cmd_delete_client(int p_fd, char *p_addr, char *p_port)
{
	unsigned long m_addr;
	short m_port;
	int i;	
	if(strlen(p_port)==0)
		return 2; // para wrong
	m_port=(short)(atoi(p_port));
	m_addr=ntohl(inet_addr(p_addr));
	for(i=0;i<MAXREC;++i)
	{
		if(rc[i].r_fd&&(rc[i].r_add==m_addr)&&
			(rc[i].r_port==m_port))
		{
			Close(rc[i].r_fd);
			init_rec(&rc[i]);
			return 0;
		}
	}   	// include this part will be able to 
		// disconnect connection from message receive port

	for(i=0;i<MAXDIS;++i)
	{
		if(dc[i].d_fd&&(dc[i].d_add==m_addr)&&
			(dc[i].d_port==m_port))
		{
			Close(dc[i].d_fd);
			init_dis(&dc[i]);
			return 0;
		}
	}

	for(i=0;i<MAXCMD;++i)
	{
		if(cc[i].c_fd&&(cc[i].c_add==m_addr)&&
			(cc[i].c_port==m_port))
		{
			if(cc[i].c_fd!=p_fd)
			{
				Close(cc[i].c_fd);
				init_cmd(&cc[i]);
				return 0;
			}
			else
			{
				return 3; //suicide
			}
		}
	}   // include will be able disconnect connection from cmd port
	return 1; // no such client
}
int cmd_delete_message(char* p_addr,char* p_port)
{
	unsigned long m_addr;
	short m_port;
	int i;	
	if(strlen(p_port)==0)
		return 2; // para wrong
	m_port=(short)(atoi(p_port));
	m_addr=ntohl(inet_addr(p_addr));
	for(i=0;i<MAXREC;++i)
	{
		if(rc[i].r_fd&&(rc[i].r_add==m_addr)&&
			(rc[i].r_port==m_port)&&(rc[i].r_bytes))
		{
			rc[i].r_messbuf[0]=0;
			rc[i].r_bytes=0;
			return 0;
		}
	}

	return 1; // no such message
}

