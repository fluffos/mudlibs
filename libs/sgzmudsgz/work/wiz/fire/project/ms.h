/******************************************************************
* ms.h
* head file for the message center 
*******************************************************************/
#include <time.h>
#define M_WELCOME "Welcome to use message center :)\n\n"
#define M_HELPTITLE "Use help to check the command list.\n\n"
#define M_NOCONN "Sorry, all connections are used, please try later.\n"
#define M_PROM ":-) "
#define M_PROM2 "==> "

#define M_NEWLINE "\n"
#define M_WAITPASS "Please input your password.\n\n"
#define M_UNKNOWCMD "Unknow command or wrong parameters.\n"
#define M_WAITLOG "Please login (input user) first.\n\n"
#define M_PASSCORRECT "Password is right, you are succeccfully login.\n\n"
#define M_PASSWRONG "Sorry, password is not correct, please retry. \n\n"
#define M_NOPASSNEED "You have login, no password needed. \n\n"
#define M_CLIENTLISTTITLE "		The list of client currently connected\n"
#define M_MESSAGELISTTITLE "		The list of message currently stored\n"
#define M_MESSBAR "===============================================================================\n"
#define M_MESSBAR2 "-------------------------------------------------------------------------------\n"
#define M_CLIENTLISTTITLE2 "        Type      Fdesc        Address     Port          Connect time\n"
#define M_MESSAGELISTTITLE2 "Message Length    Fdesc        Address     Port          Connect time\n"  
#define M_DELETECLIENTSUCC "The client is successfully deleted.\n\n"
#define M_DELETEMESSAGESUCC "The message is successfully deleted.\n\n"
#define M_NOSUCHCLIENT "Can't find the client, please check address and port.\n\n"
#define M_NOSUCHMESSAGE "Can't find the message, please check address and port.\n\n"
#define M_DELETESELF "Delete YOURSELF ? better to use quit :(\n\n"


/* the ms.h */
#define MAXBUFFSIZE 2048
/* the max number of bytes of message one rec connect can store */
#define MAXREC 3
/* the max number of receive connection */
#define MAXDIS 2
/* the max number of display connection */
#define MAXCMD 2
/* the max number of control connection */
#define RECPORT 5000
/* the receive port */
#define DISPORT 5100
/* the display port */
#define CMDPORT 5200
/* this is used to handle the range for a bind test */
#define PORTRANGE 100
/* the control port */
#define MAXCMD2 120
/* this means a command include it's parrs can't over 50 byte longth */
#define PARMAX 30
/* none of cmd, para1 and para2 can exceed this len */
/* this struct is used for the server to store the 
relevant information of client conneced with server's
receive port */
struct recclient
{
	int r_fd; /* if fd equals zero means no connection */
	unsigned long r_add;
	short r_port;
	time_t r_contime; /* the time of the connection has been built */
	time_t r_rectime; /* the time of the last message received */
	int r_tbytes; /* total bytes of message has been received */
	int r_bytes; /* how many bytes of message in messbuf */
	char r_messbuf[MAXBUFFSIZE];
};

struct cmdclient
{
	int c_fd; /* if fd equals zero means no connection */
	unsigned long c_add;
	short c_port;
	int c_stat; /* 0 means just cor 
			1 means wait pass for user
			2 means normal connect
			3 means wait pass for shutdown
			*/
	time_t c_contime; /* the time of the connection has been built */
	char c_name[10]; /* the user name */
	char c_pass[10]; /* the password */
	char c_cmd[MAXCMD2]; /* the maxmum of bytes for a complete cmd 
		incude para can't exceed half of MAXCMD2 */
	int c_cmdpoint; /* used to identify the current position of cmd */
};


struct disclient
{
	int d_fd; /* if fd equals zero means no connection */
	unsigned long d_add;
	short d_port;
	time_t d_contime; /* the time of the connection has been built */
};


void init_rec(struct recclient* rc); /* this program is used to initiate 
					the receive client struct */
void init_dis(struct disclient* rc); /* this program is used to initiate 
					the display client struct */
int ser_socket(int p_port,int* real_port);
int cmd_para(char *input,int len,char *cmd,char *para1,char *para2,char *para3);
void cmd_help(int p_fd);
int pass_verify(char *name,char *pass);
void cmd_list_client(int p_fd);
int cmd_do(int p_id,char* p_cmd,char* p_para1,char* p_para2,char* para3);
void cmd_list_message(int p_fd);
int cmd_delete_message(char* p_para2,char* p_para3);
unsigned long messwrap(char* input,char* output,unsigned long len);
int cli_socket(char *ser_add,int p_port,int *real_port);