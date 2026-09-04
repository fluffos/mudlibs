#ifndef __MUDLIB__
#define __MUDLIB__

//  The base distribution mudlib name.  

#define MUDLIB_NAME                     "仙侣情缘之紫藤站"
#define MUDLIB_VERSION_NUMBER	        "3.2"
#define MUDLIB_VERSION                  (MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
#define MUDLIB_MUDOS_VERSION            "MudOS v22.2b11"

#define INTERMUD_MUD_NAME               "XLQY"
#define INTERMUD_NAME                   "仙侣情缘之紫藤站"
#define LOCALHOST                       "58.61.156.182"
#define CHINESE_MUD_NAME                "【仙侣情缘】"
#define WEB_SITE 			"【仙侣情缘】ONLINE V3.0"
#define MUD_EMAIL                       "dragonbell@163.com"
#define MUD_ADMIN                       "dragonbell@163.com"
#define MUD_IP                          "219.140.78.6 6666"
#define MUD_BIND                        "二零零四年五月二十日"
#define MUD_WEB                         "http://www.hbisp.com"
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
