#ifndef __FTP_D_H
#define __FTP_D_H
#define FTP_DEBUG

#define MAX_IDLE_TIME 540     // 9分钟
#define LOG(str) log_file("static/ftpd", str)


#define FTP_USERS ({ "nerd", "pig" })
#define PERM_DENIED(x) receive("550 " + x + " Permission denied.\n")
#define LOGIN_FIRST receive ("503 Log in with USER first.\n")
#define DEFAULT_MSG ".message"

#define ASCII 0
#define BINARY 1

#ifdef FTP_DEBUG
#define DBG(str) log_file("static/ftp_debug", str)
#else
#define DBG(str)
#endif //FTP_DEBUG

void cmdQuit( string * reqs );
void cmdSystemType( string * reqs );
void cmdUser(string*);
void cmdPass(string*);
void cmdPort(string*);
void cmdNoOp(string*);
void cmdCwd(string *);
void cmdList(string*);
void cmdPwd(string*);

#endif
