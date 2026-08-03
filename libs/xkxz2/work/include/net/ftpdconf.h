/* ftpdconf.h： ftpd 内部配置 */

#ifndef _FTPDCONF_H
#define _FTPDCONF_H

#include <mudlib.h>
#include "net/socket.h"

/*
-----------------------------------------------
   标准定义
-----------------------------------------------
*/

/* FTP 的端口*/
#define FTPD_PORT 6000

/* 最大延时 */
#define FTPD_TIMEOUT 900

/* 最大发呆时间 */
#define MAX_FTPD_IDLE 7200
 
/* 个人主目录 */
#define HOME_DIR(name)  user_cwd(name)

/* 欢迎信息 */
#define LOGIN_MSG       "/adm/etc/ftpd_welcome"

/* MUD 名称 */
#define THE_MUD_NAME    INTERMUD_MUD_NAME

/* 最大用户数 */
#define FTPD_MAX_USERS 4

/*Mudos 的版本 */
#define THE_VERSION __VERSION__

/* 数据流出大小，最好是 1024
 */
#define BLOCK_SIZE 1024

/* bug 记录送给谁？ */
#define FTP_BUGS_EMAIL "gzjjgod@21cn.com"

/*
-----------------------------------------------
   杂项定义
-----------------------------------------------
*/

/*定义是否允许匿名登录 */
#define ANONYMOUS_FTP

/* 定义是否允许没有个人目录的巫师登录 */
#define GUEST_WIZARD_FTP

/* 下面是一些专门记录定义 */
#undef FILE_LOCKING

#undef CHECK_SITE

#define MESSAGE_FILES

#if 0
/*
 * 读权限制
 */
#define VALID_READ       0		// 依靠 valid_read() 函数
#define RESTRICTED_READ  1		// 同上，但只能读下面的目录
#define WRITE_LIMIT_READ 2		// 由写权控制
#endif

/* 读的等级 */
#define READ_LEVEL (VALID_READ)

#if 0
/*
 * 下面是写的限制（jjgod 修改）
 */
#define VALID_WRITE      0		// 依靠 valid_write() 函数
#define RESTRICTED_WRITE 1		// 同上，但只能写下面的目录
#define READ_ONLY        2		// 完全不能写
#endif

/* 定义读写等级 */
#define WRITE_LEVEL (VALID_WRITE)

/*这两个目录是限制读写的 */
#define PUB_DIR "/open"
#define FTP_DIR "/ftp"

#define FTP_USERS ({"jjgod", "where",  "ygunq",})
/*
-----------------------------------------------
   debug 定义
-----------------------------------------------
*/

/* define DEBUG 来启用 DEBUG 消息*/
#undef DEBUG

/* 告诉一个用户 debug 信息 */
#define TP_CRE "jjgod"

/*
-----------------------------------------------
   LOG 文件定义
-----------------------------------------------
*/

/* undefine 这个来取消所有的纪录 */
#define LOGGING

#ifdef LOGGING
/* 记录所有连接 */
#define LOG_CONNECT
/* 记录文件名 */
#define LOG_FILE        "FTPD"
/*记录连接时间 */
#define LOG_TIME
/* 记录指令连接 */
#define LOG_CD_SIZE
/* 记录失败的连接 */
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
	连接检查
-----------------------------------------------
*/

// 限制匿名 FTP

#if defined(ANONYMOUS_FTP) && defined(FTP_USERS)
#undef ANONYMOUS_FTP
#endif

#if defined(ANONYMOUS_FTP) && !defined(FTP_DIR)
#undef ANONYMOUS_FTP
#endif

// 假如巫师没有/u/id/ 目录，就要送到这个目录去
#if defined(GUEST_WIZARD_FTP) && !defined(PUB_DIR)
#define PUB_DIR "/"
#endif

#endif /* _FTPDCONF_H */
