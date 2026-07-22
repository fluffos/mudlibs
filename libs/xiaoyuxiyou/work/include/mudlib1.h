#ifndef __MUDLIB__
#define __MUDLIB__

//  The base distribution mudlib name.  

#define MUDLIB_NAME                     "星月传奇"
#define VERSION_NAME                    "神话传说"
#define MUDLIB_VERSION_NAME		"神话传说"
#define MUDLIB_VERSION_NUMBER		"3.0"
#define MUDLIB_VERSION_CH		"Ⅲ"
#define MUDLIB_VERSION			(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
#define MUDLIB_FULL_NAME		(HIC+MUDLIB_NAME+HIR+MUDLIB_VERSION_CH+HIW"·"+HIG+VERSION_NAME+NOR) //星月传奇Ⅲ·神话传说
#define MUDLIB_LOCAL                    "61.136.145.187 6666"
#define MUDLIB_COPYRIGHT                "Copyright 2000-2010  The Myth & The Legend"

#define INTERMUD_MUD_NAME               "XYCQ"
#define INTERMUD_NAME                   "星月传奇"
#define INTMUDLIB_VERSION_NUMBER	"V 3-0.0"
#define INTMUDLIB_VERSION_CH		"Ⅲ"
#define INTMUDLIB_FULL_NAME		(INTERMUD_MUD_NAME+" "+INTMUDLIB_VERSION_CH+" "INTMUDLIB_VERSION_NUMBER) //XYCQ Ⅲ 3.0
#define CHINESE_MUD_NAME                "星月传奇"
#define MUD_ADMIN                       "lingjingxue@sina.com"
#define MUD_WEB                         "http://www.xycq.com"
#define MUD_BBS                       	"http://www.xycq.com"
#define MUD_QQ                         	"8389392"
#define MUDLIB_ENCODING                 "GB"

#endif

// mon 4/27/98 for "vote" command and the piggy room.
#define MAX_VOTES_PER_SITE   2
// maximum votes accepted for one site.
#define VOTER_SITE   0
// this defines what is one voting site. can either be 0 or 1.
// 0: use the first 3 fields of numerical IP as a site.
// 1: use the full 4 fileds of numerical IP as a site.

#undef GB_AND_BIG5
// define this to allow both GB and BIG5 players.
// undefine will only allow GB players.

#undef INTERMUD_ALL_MUD
// define this if want to connect with ALL muds.
// undef this if only want to connect with Chinese Muds.
// Chinese muds is defined as either their mudlib is ES2 or they
// have ENCODING field set.

