// server.h

//__________索引__________
#define FILE_NAME 1
#define FILE_SIZE 2
#define TYPE 3
#define BUFFER 4
#define VALID 5
#define IP 6
#define PORT 7
#define PASS 8
#define FILE_POS 9
#define STATE 10
#define DOING 11
#define WAIT 12
#define FINISH 13
#define	SFLAG 14
#define CFLAG 15
#define ASCII 16
#define BINARY 17
#define RATE 18
#define VALID_SEND 19
#define RESET_SEND 20
#define SHOW_SEND 21
#define WAIT_POT 22
#define WAIT_FILE 23
#define STOP 24
#define MAX_FILE 25
#define FINISH_FILE 26
#define SHOW 27
#define CMD 28
#define FILE 29
#define DOMAIN 30
#define TFLAG 31
#define HFLAG 32
#define HTTP_OUT 33
#define HTTP_TYPE 34
#define DOWNLOAD 35
#define DOWNLOADING 36

//________________信息头格式_________________
#define VALID_CHECK "START$%s:%s@%s:%d#%dEND"
#define REPLY_MESSAGE "REPLY@@@%d#%s@@@END"
#define SHOW_MESSAGE "SHOW@#$%d@@@%s@#$END"
#define CMD_MESSAGE "CMD*(%s)!!!(%s)#%d#END"
// HTTP协议
#define HTTP_GET "%*sGET /%s HTTP/%*s"
#define HTTP_POST "%*sPOST /%s HTTP/%*s"
#define CGI "%*scgi-bin/%s"

//__________________目录_____________________
// WEB文件夹
#define WEB_DIR "/web/"
#define CGI_DIR "/web/cgi-bin/"
