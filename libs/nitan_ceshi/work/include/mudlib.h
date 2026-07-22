#ifndef __MUDLIB__
#define __MUDLIB__

#include "getconfig.h"

//  The base distribution mudlib name.  

// MUDLIB information
#define MUDLIB_NAME             "NITAN"
#define MUDLIB_VERSION_NUMBER   "3.0"
#define MUDLIB_VERSION		(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)

#define INTERMUD_MUD_NAME	((string) CONFIG_D->query_string("internet mud name"))
#define CHINESE_MUD_NAME	LOCAL_MUD_NAME()
#define MUD_DRIVER              ((string) CONFIG_D->query_string("mudos"))
#define MUD_TYPE                "NITAN3"
#define	MUD_ENCODING		((string) CONFIG_D->query_string("encoding"))

// MAIL information
#define SMTP_SERVER             ((string) CONFIG_D->query_string("smtp server"))
#define SMTP_DOMAIN             ((string) CONFIG_D->query_string("smtp domain"))
#define SENDER                  ((string) CONFIG_D->query_string("smtp sender"))

#define MUD_ADMIN               "lonely-21@163.com"
#define MUD_WEB                 "http://www.chinesemud.com"

#define DB_HOST                 ((string) CONFIG_D->query_string("db host"))
#define DB_USER                 ((string) CONFIG_D->query_string("db user"))
#define DATABASE                ((string) CONFIG_D->query_string("db database"))
#define LOCAL_STATION           ((string) CONFIG_D->query_string("local host"))

// 所有监听的节点
#define MUDLIST_DNS1            ((string) CONFIG_D->query_string("mudlist1"))
#define MUDLIST_DNS2            ((string) CONFIG_D->query_string("mudlist2"))
#define MUDLIST_DNS3            ((string) CONFIG_D->query_string("mudlist3"))
#define MUDLIST_DNS4            ((string) CONFIG_D->query_string("mudlist4"))
#define MUDLIST_DNS5            ((string) CONFIG_D->query_string("mudlist5"))
#define MUDLIST_DNS6            ((string) CONFIG_D->query_string("mudlist6"))
#define MUDLIST_DNS7            ((string) CONFIG_D->query_string("mudlist7"))
#define MUDLIST_DNS8            ((string) CONFIG_D->query_string("mudlist8"))
#define MUDLIST_DNS9            ((string) CONFIG_D->query_string("mudlist9"))

#endif
