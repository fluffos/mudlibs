/* ftpd.h */
#ifndef __FTPD_H
#define __FTPD_H
#define POS     1
#define DATA        2
#define USER_NAME   3
#define LOGGED_IN   4
#define CWD     5
#define LEN     6
#define PARENT_FD   7
#define DATA_FD     8
#define DATA_ADDR   9
#define LAST_DATA   10
#define DATA_PORT   11
#define FILE        12
#define TYPE        13
#define DOWNLOAD    14
#define PATH        15
#define APPEND      16
#define CONNECTED   17
#define USER_SITE   18
#define STRING      19
#define BINARY      20
#define FROMNAME    21
#define IDLE_SETTING    22
#define TRANSFER_MODE   23
#define FTP_TIME        (sprintf("[%s] ", ctime(time())[4..15]))
#define UNAME   socket_info[ fd ][ USER_NAME ]
#define UCWD    socket_info[ fd ][ CWD ]
#define UTYPE   socket_info[ fd ][ TYPE ]
#define USITE   socket_info[ fd ][ USER_SITE ]
#define UPATH   socket_info[ fd ][ PATH ]
#define UDATA   socket_info[ fd ][ DATA ]
#define MAX_UNIQUE_TRIES 10
#define MONTHS ({ "一月", "二月", "三月", "四月", "五月", "六月", \
                  "七月", "八月", "九月", "十月", "十一月", "十二月" })
#define SECS_IN_YEAR (365 * 24 * 60 * 60)
/*
 * Listed of recognized commands in order defined in RFC 765
 *   ({ Command, Implemented?, Help text })
 */
mapping cmdtab = ([
    "user" : ({ "USER", 1, "<sp> 用户名：" }),
    "pass" : ({ "PASS", 1, "<sp> 密码：" }),
    "acct" : ({ "ACCT", 0, "(指定账号)" }),
    "smnt" : ({ "SMNT", 0, "(结构装置)" }),
    "rein" : ({ "REIN", 0, "(reinitialize 服务器情况)" }),
    "quit" : ({ "QUIT", 1, "(终止服务)", }),
    "port" : ({ "PORT", 1, "<sp> b0, b1, b2, b3, b4" }),
    "pasv" : ({ "PASV", 0, "(设置服务器为被动模式)" }),
    "type" : ({ "TYPE", 1, "<sp> [ A | E | I | L ]" }),
    "stru" : ({ "STRU", 0, "(说明文件结构)" }),
    "mode" : ({ "MODE", 0, "(说明连接模式)" }),
    "retr" : ({ "RETR", 1, "<sp> 文件名" }),
    "stor" : ({ "STOR", 1, "<sp> 文件名" }),
    "appe" : ({ "APPE", 1, "<sp> 文件名" }),
    "mlfl" : ({ "MLFL", 0, "(mail文件)" }),
    "mail" : ({ "MAIL", 0, "(寄信给用户)" }),
    "msnd" : ({ "MSND", 0, "(mail send to terminal)" }),
    "msom" : ({ "MSOM", 0, "(mail send to terminal or mailbox)" }),
    "msam" : ({ "MSAM", 0, "(mail send to terminal and mailbox)" }),
    "mrsq" : ({ "MRSQ", 0, "(mail recipient scheme question)" }),
    "mrcp" : ({ "MRCP", 0, "(mail recipient)" }),
    "allo" : ({ "ALLO", 1, "allocate storage (vacuously)" }),
    "rest" : ({ "REST", 0, "(重新开始指令)" }),
    "rnfr" : ({ "RNFR", 1, "<sp> 文件名" }),
    "rnto" : ({ "RNTO", 1, "<sp> 文件名" }),
    "abor" : ({ "ABOR", 1, "(中断操作)" }),
    "dele" : ({ "DELE", 1, "<sp> 文件名" }),
    "cwd"  : ({ "CWD" , 1, "[ <sp> 目录名 ]" }),
    "xcwd" : ({ "XCWD", 1, "[ <sp> 目录名 ]" }),
    "list" : ({ "LIST", 1, "[ <sp> 路径名 ]" }),
    "nlst" : ({ "NLST", 1, "[ <sp> 路径名 ]" }),
    "site" : ({ "SITE", 1, "site-cmd [ <sp> arguments ]" }),
    "syst" : ({ "SYST", 1, "(获得操作系统类型)" }),
    "stat" : ({ "STAT", 1, "[ <sp> 路径名 ]" }),
    "help" : ({ "HELP", 1, "[ <sp> <string> ]" }),
    "noop" : ({ "NOOP", 1, "" }),
    "mkd"  : ({ "MKD" , 1, "<sp> 路径名" }),
    "xmkd" : ({ "XMKD", 1, "<sp> 路径名" }),
    "rmd"  : ({ "RMD" , 1, "<sp> 路径名" }),
    "xrmd" : ({ "XRMD", 1, "<sp> 路径名" }),
    "pwd"  : ({ "PWD" , 1, "(返回当前目录)" }),
    "xpwd" : ({ "XPWD", 1, "(返回当前目录)" }),
    "cdup" : ({ "CDUP", 1, "(移至父目录)" }),
    "xcup" : ({ "XCUP", 1, "(移至父目录)" }),
    "stou" : ({ "STOU", 1, "<sp> 文件名" }),
    "size" : ({ "SIZE", 1, "<sp> 路径名" }),
    "mdtm" : ({ "MDTM", 1, "<sp> 路径名" })
]);
mapping sitecmdtab = ([
    "idle"  : ({ "USER",  1, "[ <sp> timeout ]" }),
    "umask" : ({ "UMASK", 0, "[ <sp> umask ]" }),
    "chmod" : ({ "CHMOD", 0, "<sp> path-name" }),
    "time"  : ({ "TIME",  1, "(return local time)" }),
    "help"  : ({ "HELP",  1, "[ <sp> <string> ]" })
]);
#define PERMISSION_DENIED550(S) socket_write( fd, sprintf( \
      "550 Permission denied to %s.\n", S) )
#define PERMISSION_DENIED553(S) socket_write( fd, sprintf( \
      "553 Permission denied to %s.\n", S) )
/*
 * these flags determine read level access
 */
#define VALID_READ       0              // rely on valid_read()
#define RESTRICTED_READ  1              // ditto, but limited to public dirs
#define WRITE_LIMIT_READ 2              // access limited by write access
/*
 * these flags determine write level access
 */
#define VALID_WRITE      0              // rely on valid_write()
#define RESTRICTED_WRITE 1              // ditto, but limited to public dirs
#define READ_ONLY        2              // no write access, at all
#endif /* __FTPD_H */
