#ifndef __MUDLIB__
#define __MUDLIB__
#include "getconfig.h"
//  The base distribution mudlib name.
// MUDLIB information
#define MUDLIB_NAME             "axtj2"
#define MUDLIB_VERSION_MUDOS    "fluffos2018"
#define MUDLIB_VERSION_NUMBER	"1.0"
#define MUDLIB_VERSION		(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
#define INTERMUD_MUD_NAME	((string) CONFIG_D->query_string("internet mud name"))
#define INTERMUD_NAME           "擎日挽月"
#define VERSION_NAME            "翱翔天际之擎日挽月"
#define CHINESE_MUD_NAME	LOCAL_MUD_NAME()
#define MUD_ADMIN               "lyh_cliff@citiz.net"
#define MUD_IP                  " 220.112.65.101 6666"
#define MUD_BIND                "2004年10月1日"
#define MUD_WEB                 "http://axtj.oicp.net"
#define MUDLIB_ENCODING         "GB"
#define MUD_DRIVER              ((string) CONFIG_D->query_string("mudos"))
#define PURGE_TIMES             "普通用户90天"
#define LOCALHOST               "localhost"
// MAIL information
#define SMTP_SERVER             ((string) CONFIG_D->query_string("smtp server"))
#define SMTP_DOMAIN             ((string) CONFIG_D->query_string("smtp domain"))
#define SENDER                  ((string) CONFIG_D->query_string("smtp sender"))
// 所有监听的节点
#define MUDLIST_DNS1            ((string) CONFIG_D->query_string("mudlist1"))
#define MUDLIST_DNS2            ((string) CONFIG_D->query_string("mudlist2"))
#define MUDLIST_DNS3            ((string) CONFIG_D->query_string("mudlist3"))
#define MUDLIST_DNS4            ((string) CONFIG_D->query_string("mudlist4"))
#define MUDLIST_DNS5            ((string) CONFIG_D->query_string("mudlist5"))
#define MAX_VOTES_PER_SITE   2
#define VOTER_SITE   0
#endif
#undef INTERMUD_ALL_MUD
