/* ftpd.h */
#ifndef __FTPD_H
#define __FTPD_H

#define POS		1
#define DATA		2
#define USER_NAME	3
#define LOGGED_IN	4
#define CWD		5
#define LEN		6
#define PARENT_FD	7
#define DATA_FD		8
#define DATA_ADDR	9
#define LAST_DATA	10
#define DATA_PORT	11
#define FILE		12
#define TYPE		13
#define DOWNLOAD	14
#define PATH		15
#define APPEND		16
#define CONNECTED	17
#define USER_SITE	18
#define STRING		19
#define BINARY		20
#define FROMNAME	21
#define IDLE_SETTING	22

#define FTP_TIME        (sprintf("[%s] ", ctime(time())[4..15]))
#define UNAME   socket_info[ fd ][ USER_NAME ]
#define UCWD    socket_info[ fd ][ CWD ]
#define UTYPE   socket_info[ fd ][ TYPE ]
#define USITE   socket_info[ fd ][ USER_SITE ]
#define UPATH   socket_info[ fd ][ PATH ]
#define UDATA   socket_info[ fd ][ DATA ]

#define MAX_UNIQUE_TRIES 10

#define MONTHS ({ "Jan", "Feb", "Mar", "Apr", "May", "Jun", \
                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" })

#define SECS_IN_YEAR (365 * 24 * 60 * 60)

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
