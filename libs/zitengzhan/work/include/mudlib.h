#ifndef __MUDLIB__
#define __MUDLIB__

//  The base distribution mudlib name.  

#define MUDLIB_NAME                     "大唐西游之紫藤站"
#define MUDLIB_VERSION_NUMBER	        "2013版"
#define MUDLIB_VERSION			(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
#define MUDLIB_MUDOS_VERSION            "MudOS v22.2b11"

#define INTERMUD_MUD_NAME               "XDTMUD"
#define INTERMUD_NAME                   "大唐西游之紫藤站"
#define LOCALHOST                       "220.161.4.202"
#define CHINESE_MUD_NAME                "【紫藤西游】"
#define WEB_SITE 			"【大唐西游】ONLINE V3.0"
#define MUD_EMAIL                       "81446878@qq.com"
#define MUD_ADMIN                       "81446878@qq.com"
#define MUD_IP                          "220.161.4.202 6666"
#define MUD_BIND                        "2013年6月1日"
#define MUD_WEB                         " http://www.zpxzzx.org/bbs"
#define PURGE_TIMES                     "永久"
#define MUDLIB_ENCODING                 "GB"

#endif

// mon 4/27/98 for "vote" command and the piggy room.
#define MAX_VOTES_PER_SITE   2
// maximum votes accepted for one site.
#define VOTER_SITE   0
// this defines what is one voting site. can either be 0 or 1.
// 0: use the first 3 fields of numerical IP as a site.
// 1: use the full 4 fileds of numerical IP as a site.

#define GB_AND_BIG5
// define this to allow both GB and BIG5 players.
// undefine will only allow GB players.

#undef INTERMUD_ALL_MUD
// define this if want to connect with ALL muds.
// undef this if only want to connect with Chinese Muds.
// Chinese muds is defined as either their mudlib is ES2 or they
// have ENCODING field set.
