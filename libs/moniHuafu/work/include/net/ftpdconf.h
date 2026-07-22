/* ftpdconf.h: ftpd 配置 */

#ifndef _FTPDCONF_H
#define _FTPDCONF_H

// 下面的定义在 <globals.h> 中已经自动包含了。
// #include <uid.h>        /* 获得为tmi-2 MUD中 ROOT_UID 的定义*/
// #include "config.h"

#include <mudlib.h> /* 获得mudlib的主要内容 */
#include "net/socket.h" /* 不同的 socket 定义 */

/*
-----------------------------------------------
  标准定义
-----------------------------------------------
*/

/* FTPD_PORT 端口号码 on which the ftp daemon will listen.  On a UNIX
   system the user should type: ftp tmi.lp.mud.org 5554
   (depending on the hostname of the MUD and the port # set below).
*/
#define FTPD_PORT 21	// 还是重新用回21算了

/* 最大沿时。
 * this is used as the default for all connections--see MAX_FTPD_IDLE
 */
#define FTPD_TIMEOUT 900

/* 最大发呆时间。
 * note that when a user logs into ftp, they are assigned the value in
 * FTPD_TIMEOUT and may manually adjust it up to the limit of MAX_FTPD_IDLE
 */
#define MAX_FTPD_IDLE 7200
 
/* HOME_DIR: 用户开始连入时的路径 */
#define HOME_DIR(name)  user_cwd(name) /* on TMI-2 */

/* 显示给连接成功者看的欢迎画面。
 * displayed upon every successful login.
 */
#define LOGIN_MSG       "/adm/etc/ftpd_welcome"

/* MUD的名字 */
#define THE_MUD_NAME    INTERMUD_MUD_NAME

/* 最大FTP用户数，如果多了会严重影响系统速度！ */
#define FTPD_MAX_USERS 4

/*driver的版本 (__VERSION__ on MudOS muds) */
#define THE_VERSION __VERSION__

/* Set this to be the size of each outgoing block of data during
 * file transfers.  This hasn't been tested with any value other
 * than 1024, so its generally good to leave this alone.
 */
#define BLOCK_SIZE 1024

/* 错误报告发送给谁 */
#define FTP_BUGS_EMAIL "gzjjgod@163.net"

/*
-----------------------------------------------
   misc support defines.以下是有关读写权限的设置
-----------------------------------------------
*/

/* 允许 "anonymous" ftp 连接 */
#define ANONYMOUS_FTP

/* define this to allow guest wizards (without home directories) to login */
#define GUEST_WIZARD_FTP

/* define this to support advisory file locking */
#undef FILE_LOCKING

/* define this to support individual site checking (from .login file) */
#undef CHECK_SITE

/* define this to support .message files sent to user when they "cd" */
#define MESSAGE_FILES

#if 0
/*
 * (copied from ftpd.h)
 * these flags determine read level access (values are intentionally unique...
 * and are manually generated, so don't change them)
 */
#define VALID_READ       0              // rely on valid_read()
#define RESTRICTED_READ  1              // ditto, but limited to public dirs
#define WRITE_LIMIT_READ 2              // access limited by write access
#endif

/* define as (ie set to) one of the flags above */
#define READ_LEVEL (VALID_READ)

#if 0
/*
 * (copied from ftpd.h)
 * these flags determine write level access (values are intentionally unique...
 * and are manually generated, so don't change them)
 */
#define VALID_WRITE      0              // rely on valid_write()
#define RESTRICTED_WRITE 1              // ditto, but limited to public dirs
#define READ_ONLY        2              // no write access, at all
#endif

/* define as (ie set to) one of the flags above */
#define WRITE_LEVEL (RESTRICTED_WRITE)

/* define the following public dirs that you'll limit access to
 * for RESTRICTED_READ and/or RESTRICTED_WRITE; undefine any for which
 * the directory doesn't exist on your system
 */
#define PUB_DIR "/"
#define FTP_DIR "/ftp"

/* define this array as the only set of users permitted to use ftp
 * Example:
 *   #define FTP_USERS ({ "buddha", "mobydick", "watcher" })
 */
#undef FTP_USERS

/*
-----------------------------------------------
   debugging defines.
-----------------------------------------------
*/

/* define DEBUG to enable debugging info */
#undef DEBUG

/* player to whom to "tell" debugging info */
#define TP_CRE "ken"

/*
-----------------------------------------------
  纪录信息定义
-----------------------------------------------
*/

/* undefine this to disable all logging */
#define LOGGING

#ifdef LOGGING
/* define this to log all connections */
#define LOG_CONNECT
/* define this to determine where to log all file xfers */
#define LOG_FILE        "FTPD"
/* define this to put a time stamp before all log entries */
#define LOG_TIME
/* define this to log cd's, time stamp, and file size commands */
#define LOG_CD_SIZE
/* define this to log failed connections */
#define LOG_NO_CONNECT

#else

#undef LOG_CONNECT
#undef LOG_FILE
#undef LOG_CD_SIZE
#undef LOG_TIME
#undef LOG_NO_CONNECT

#endif /* LOGGING */

/*
-----------------------------------------------
   连 接 验 证
-----------------------------------------------
*/

/* restricting ftp to a limited number of users and having anon ftp
 * at the same time is pointless
 */
#if defined(ANONYMOUS_FTP) && defined(FTP_USERS)
#undef ANONYMOUS_FTP
#endif

/*
 * 服务器必须限制匿名登陆的用户使用被限制的目录
 */
#if defined(ANONYMOUS_FTP) && !defined(FTP_DIR)
#undef ANONYMOUS_FTP
#endif

/* guest wizards, if permitted to login, need some place to go */
#if defined(GUEST_WIZARD_FTP) && !defined(PUB_DIR)
#define PUB_DIR "/"
#endif

#endif /* _FTPDCONF_H */

