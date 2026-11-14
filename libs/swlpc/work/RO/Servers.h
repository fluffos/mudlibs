/*
 * This include file lists most of the standard servers.
 *
 * If yow want to use one of these:
 *	FIRST: check to see if there is an include file listed (usually here)
 * 	       which does all the definitions required to use that server.
 *	       If there is one, you should #include it - it usually has a
 *	       number of useful definitions (or we think we will be adding
 *	       them!).  This might save you much pain when we go and (for
 *	       instance) add a new stat to player objects, or make other mods
 *	       that affect backward compatibility (like adding strong types).
 *	       If you couldn't find a specific include file, but think one
 *	       might be useful (now or later), mail a god.
 * 	        
 *		The wizard command 'servers' is useful to search for
 *		defined servers.
 *
 *	NEXT:  Use the name defined here.  If the object isn't defined here,
 *	       and you think it should be, mail a god.
 *
 *	This file is kept in RO because it is included by things that are
 *	supposed to be in secure places.
 */

/* less err messages */

#ifndef	STDNAMES_H
#define	STDNAMES_H

/* Plenty of standard servers are defined in Consts.h (like master) */

#include "Consts.h"

/*
 * STANDARD SERVERS.  Servers not listed here are usually accessed
 * using an include file - eg #include "gender.h".
 */

/* things which make things for you - used often, so short names */

#define	ARMOURER		"std/armourer"
#define	MONSTERER		"std/monsterer"
#define	WEAPONER		"std/weaponer"
#define MONEYER			"std/money"
#define ITEMER			"std/itemer"
#define GEMMER                  "std/gem/gemmer"
#define ITEMER			"std/itemer"
#define TAILOR          "std/tailor"
#define OUTFIT			"std/itemer"
#define CLOCK			"obj/clock"
#define BASE			"RO/base_object"
#define GENDER			"lib/gender"
#define NPC_PERSIST_SERV        "/P/npc"

/* player control */

#define	LOGIN_SERVER		"S/gatekeeper"
#define	BANISH_SERV		"std/banish"
#define	BAR_IP_SERV		"std/bar"
#define	WHINGE_SERV		"std/priority"
#define	PLAYER_REMOVER		"std/remove_player"

/* Economy, etc */

#define BANK			"players/dredd/economy/bank_register"
#define BANK_REGISTER		"players/dredd/economy/bank_register"
#define CENTRAL_BANK		"players/dredd/economy/central_bank"
#define SHOP_SERVER		"players/dredd/economy/shop_server"

/* hooks for these should really be combined into one object */

#define	REAL_ESTATE		"players/llati/real/re"
#define	AUCTIONEERS		"players/llati/real/state"

/* Textual support */

#define MORE 			"std/more"

/* Lists, etc, supported by the world */

#define	GUILD_OPINIONS		"std/opinions"
#define	PEERAGE_SERV		"std/peerage"
#define	TOP_LIST_SERV		"std/top_list"
#define	QUEST_SERV		"guilds/quests/quest"
#define GUILD_SERV		"guilds/guild"
#define FINGER			"std/finger"

#define SHOUT			"S/shout"
#define LOG			"RO/logger"

/* inter-mud communication stuff */

#define RHOST_SERV  		"RO/remote/rhosts"
#define RCALL	  		"RO/remote/rcall"
#define RWHO			"RO/remote/rwho"
#define RTALK			"RO/remote/rtalk"
#define RBOARD			"RO/remote/rboard"

/* Daemons */

#define MAILD			"secure/mail_daemon"

/* wizard stuff */

#define	TEST_REGISTER		"std/register"
#define	WIZ_TASK_SERV		"std/wiztasklog"
#define	PLAYER_INFO_SERV	"std/player_info"
			/* ADMIN will be changed as soon as llati tells
			 * us where it should point */
#define ADMIN			"std/admin"
#define SERVLIST		"S/servers"

/* debug stuff, for tracking down odds and ends */

#define DUMP			"lib/dump"
/* #define OLDCODE                 "S/old_code" */
#define OLDCODE			"players/hunter/S/old_code"

/* random junk - too small to have #include files */

#define	NUMBERS_SERV		"lib/english"
/* lib/english referred to twice. Because? there is stuff
 * in lib/english that isn't related to numbers, and NUMBERS_SERV
 * is not a good name for such a server, IMHO - Hunter 950128
 */
#define ENGLISH			"lib/english"
#define SCORE_SERV		"RO/score"
#define	WHICH_MUD		"secure/which_mud"
#define	SHUT_DAEMON		"RO/shut"
#define STAT_SERV		"RO/stat_server"
#define SAC_SERV		"std/gem/sac_serv"
#define NAMER			"std/namer"

#define FIGHT_SERV		"std/fight_server"
#define SKILL_SERV		"std/skill_server"
#define NPC_SERV "std/npc_server"
#define INFLATION		"std/inflation"
#define RUMOUR                 "std/rumour"

#define ANON_SERV		"RO/Anonymous"

/*
 * Stuff which knows about locations.
 */

#define	MAPKNOWER		"std/map/MapKnower"
#define	SPEC_ROOMS		"std/map/spec_rooms"
#define DIRECTION		"lib/direction"

/* stuff in /lib should have headers defined I guess. */

#define MISC_LIB		"lib/misc"
#define ARRAY			"lib/arrays"
#define DATE			"lib/date"
#define STRINGS			"RO/lib/strings"
#define COLOURS			"lib/colours"
#define FORMAT			"lib/format"
#define PLURAL			"lib/plural"
#define WHOIS			"lib/whois"
#define SORT			"lib/sort"
#define SCRIPTS			"lib/scripts"
#define OUTPUT_FILE		"lib/file"
#define FILENAME		"lib/filename"
#define LEVELS			"lib/levels"
#define LOOK                    "lib/look"
#define VISION                  "lib/vision"
#define COMARGS   		"RO/lib/comargs"
#define ARG_PARSER 		"RO/lib/parser"

#define MOVE			"closed/transfer"
#define TRANSFER		"closed/transfer"

#define	AUTOSAVE_SERV		"std/autosave"
#define	EVENT_NOTIFY		"RO/EventNotify"
#define USER_SERV       "S/users"


/* temporary stuff for different drivers */
/*#define XVERB	1	*/
#define NO_SET_LIGHT

/* DO NOT! Put anything below this line. */
#endif
