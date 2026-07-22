#ifndef __MUDLIB__
#define __MUDLIB__

//  The base distribution mudlib name.  

#define MUDLIB_NAME			"小雨西游"

#define VERSION_NAME			"开元"
#define FULL_NAME			(MUDLIB_NAME + "·" + VERSION_NAME + "2007")

#define MUDLIB_NAME_E			"XYXY"
#define VERSION_NAME_E			"KY"
#define FULL_NAME_E			(MUDLIB_NAME_E + "·" + VERSION_NAME_E + "2007")

#define VERSION_NUMBER			"0.1"

#define MUDLIB_LOCAL                    "mud.xymud.com  6666"
#define MUDLIB_COPYRIGHT                "Copyright 2013-2015"
#define MUDLIB_DATE                     "2013年12月31日"

#define MUD_BBS                       	"http://pnwmud.com"
#define MUD_QQ                         	"4951331"


#define MUDLIB_VERSION_NUMBER	"1.0"
#define MUDLIB_VERSION			(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)

#define INTERMUD_MUD_NAME               "XYXY"
#define INTERMUD_NAME                   "小雨西游"
#define CHINESE_MUD_NAME                "小雨西游"
#define MUD_ADMIN                       "icezenki@yahoo.com.cn"
#define MUD_WEB                           "www.xymud.com"
#define MUDLIB_ENCODING                    "GB"

/*
#define INTERMUD_MUD_NAME               "XYXY"
#define INTERMUD_NAME                   "小雨西游"
#define CHINESE_MUD_NAME                "小雨西游"
*/
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

