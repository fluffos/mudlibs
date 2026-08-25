/* I had to recreate this file, ls.h and localtime.h as i forgot to
 * get them with ftpd.c, so they probably arnt exactly what they should
 * be.  Ahh well, they work properly, so dont fret too much :) -Dyr Nov '95
 */

#include "ls.h"

#define MASTER "/secure/master"
#define LOGIN_OB "/secure/login"

#define FR_FTP_PORT 3010
#define FTP_VERSION "-Final Realms - FTPD" 

#define USER_NAME	"user_name"
#define LOGGED_IN	"logged_in"
#define IDLE		"idle"
#define LAST_DATA	"last_data"
#define TYPE		"type"
#define POS		"pos"
#define PARENT_FD	"parent_fd"
#define LEN		"len"
#define DATA		"data"
#define DATA_FD		"data_fd"
#define DATA_ADDR	"data_addr"
#define DATA_PORT	"data_port"
#define APPEND		"append"
#define PATH		"path"
#define CWD		"cwd"


/* types */
#define STRING		1
#define DOWNLOAD	2
#define FILE		3
#define BINARY		4

/* command tables */
nosave mapping cmdtab=(["port": ({ "port", 1, "<port>" }),
                        "user": ({ "user", 1, "<user>" }),
                        "pass": ({ "pass", 1, "<password>" }),
                        "allo": ({ "allo", 1, "" }),
                        "noop": ({ "noop", 1, "" }),
                        "rnfr": ({ "rnfr", 1, "<file>" }),
                        "rnto": ({ "rnto", 1, "<file>" }),
                        "rest": ({ "rest", 1, "<offset>" }),
                        "retr": ({ "retr", 1, "<file>" }),
                        "stor": ({ "stor", 1, "<file>" }),
                        "dele": ({ "dele", 1, "<file>" }),
                        "mkd" : ({ "mkd",  1, "<dir>" }),
                        "xmkd": ({ "xmkd", 1, "<dir>" }),
                        "rmd" : ({ "rmd",  1, "<dir>" }),
                        "xrmd": ({ "xrmd", 1, "<dir>" }),
                        "appe": ({ "appe", 1, "<file>" }),
                        "help": ({ "help", 1, "[<command>]" }),
                        "site": ({ "site", 1, "<command>" }),
                        "mdtm": ({ "mdtm", 1, "<file>" }),
                        "size": ({ "size", 1, "<file>" }),
                        "stat": ({ "stat", 1, "[<file>]" }),
                        "list": ({ "list", 1, "[<file|dir>]" }),
                        "nlst": ({ "nlst", 1, "[<file|dir>]" }),
                        "pwd" : ({ "pwd",  1, "" }),
                        "xpwd": ({ "xpwd", 1, "" }),
                        "cdup": ({ "cdup", 1, "" }),
                        "xcup": ({ "xcup", 1, "" }),
                        "cwd" : ({ "cwd",  1, "<dir>" }),
                        "xcwd": ({ "xcwd", 1, "<dir>" }),
                        "quit": ({ "quit", 1, "" }),
                        "type": ({ "type", 1, "<mode>" }),
                        "abor": ({ "abor", 1, "" }),
                        "syst": ({ "syst", 1, "" }),
                        "acct": ({ "acct", 0, "" }),
                        "smnt": ({ "smnt", 0, "" }),
                        "rein": ({ "rein", 0, "" }),
                        "pasv": ({ "pasv", 0, "" }),
                        "stru": ({ "stru", 0, "" }),
                        "mode": ({ "mode", 0, "" }),
                        "mlfl": ({ "mlfl", 0, "" }),
                        "mail": ({ "mail", 0, "" }),
                        "msnd": ({ "msnd", 0, "" }),
                        "msom": ({ "msom", 0, "" }),
                        "msam": ({ "msam", 0, "" }),
                        "mrsq": ({ "mrsq", 0, "" }),
                        "mrcp": ({ "mrcp", 0, "" }),
                        "stou": ({ "stou", 0, "" }),
                      ]);

nosave mapping sitecmdtab=(["idle": ({ "idle", 1, "<seconds>" }),
                            "time": ({ "time", 1, "" }),
                            "upd" : ({ "upd",  1, "<file>" }),
                            "help": ({ "help", 1, "[<command>]" }),
                            "newer":({ "newer",0, "" }),
                            "minfo":({ "minfo",0, "" }),
                          ]);

