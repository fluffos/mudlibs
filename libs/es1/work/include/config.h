//   File  :  /include/config.h
//
//   This include file controls the major macro defines for 
//   the mudlib's base systems.
 
#ifndef __CONFIG_H
#define __CONFIG_H
 
//  The base distribution mudlib name.  
#define SAVE_EXTENSION __SAVE_EXTENSION__
#define MUDLIB_NAME				"ES_Lib"
#define MUDLIB_VERSION_NUMBER	"1.0"
#define MUDLIB_VERSION			(MUDLIB_NAME + " " + MUDLIB_VERSION_NUMBER)
// This is included for people who write code on different muds, and want
// to make it portable.  To see if they are on a tmi-type mud they can
// check #ifdef __tmi__, or for versions, #if __tmi__ > 1.0
#define __tmi__ 1.0

//  Directory path defines
#define PDATA_DIR	    "/data/std/connection/"		
#define CDATA_DIR	    "/data/std/user"
#define DATA_DIR	    "/data"
#define CONFIG_DIR	    "/adm/etc/"
#define SECURE_DIR	    "/adm/"
#define HOME_DIRS	    "/u/"
#define STUDENT_DIR	    "/student/"
//#define LOG_DIR		    "/log/"
#define WIZ_LOG_DIR     "/log/wiz/"
#define NEWS_DIR 	    "/adm/news/"
#define TMP_DIR		    "/tmp/"
#define OPEN_DIR	    "/open/"
#define HELP_DIR	    "/doc/help/"
#define WIZH_DIR	    "/doc/wizhelp/"
#define PROPH_DIR	    "/doc/properties/"
#define ARCHIVE_DIR	    "/data/attic/"
#define SIMUL_EFUN_DIR	"/adm/simul_efun/"

//  System objects
//#define USER_OB		"/std/user"
#define CONNECTION	"/std/connection"
//#define MASTER_OB	master()

// These functions are both handled by the master object in the TMI lib
#define GROUP_OB	    MASTER_OB
#define ACCESS_OB	    MASTER_OB
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
 
//  User command locations
#define WIZ_CMDS 	 "/cmds/wiz"
#define WIZX_CMDS	 "/cmds/xtra"
#define WIZF_CMDS  	 "/cmds/file"
#define STD_CMDS 	 "/cmds/std"
#define ADM_CMDS 	 "/cmds/adm"
#define OBJ_CMDS 	 "/cmds/object"
#define OPEN_CMDS    "/cmds/open"
#define MONSTER_CMDS "/cmds/std/monster"

// NEW_WIZ_PATH is used by /cmds/adm/_makewiz.c and /adm/daemons/wizmakerd.c
// You may want to change this so new wizards don't get WIZX_CMDS

#define NEW_ADM_PATH ({\
  STD_CMDS, OBJ_CMDS, WIZF_CMDS, WIZ_CMDS, WIZX_CMDS, ADM_CMDS })
  
#define NEW_ARCH_PATH ({\
  STD_CMDS, OBJ_CMDS, WIZF_CMDS, WIZ_CMDS, WIZX_CMDS, ADM_CMDS })

#define NEW_SAGE_PATH ({\
  STD_CMDS, OBJ_CMDS, WIZF_CMDS, WIZ_CMDS, WIZX_CMDS })

#define NEW_ADEPT_PATH ({\
  STD_CMDS, OBJ_CMDS, WIZF_CMDS, WIZ_CMDS })

#define NEW_WIZ_PATH ({\
  STD_CMDS, OBJ_CMDS, WIZF_CMDS, WIZ_CMDS })

#define NEW_NEWBIE_PATH ({\
  STD_CMDS, OPEN_CMDS })

#define USER_CMDS ({\
  STD_CMDS })

#define NPC_CMDS ({\
  STD_CMDS, MONSTER_CMDS })

// define the level of wizards.
#define NEW_ARCH_LEVEL   40
#define NEW_SAGE_LEVEL   30
#define NEW_ADEPT_LEVEL  25
#define NEW_WIZ_LEVEL    22
#define NEW_NEWBIE_LEVEL 20
#define NEW_USER_LEVEL    1

//  Important global mudlib informatioin
 
#define THIS_MUD 	lower_case(implode(explode(mud_name(), " "), "."))
#define ADMIN_EMAIL	"mud@cisppc2.cis.nctu.edu.tw"
 
//  The AUTO_WIZHOOD define causes all those to login as new users to be
//  granted automatic wizship, and given the PATH in the define.
 
#define AUTO_WIZHOOD NEW_ADM_PATH
//NEW_WIZ_PATH
 
// The SAFETY_SHUTDOWN define allows an admin to type "shutdown" at
// the "Press ENTER to continue" prompt and shut the game down. This
// permits you to unwedge the MUD when something is blocking commands, but
// will be destroyed if the game is restarted.

#define SAFETY_SHUTDOWN	"Yeah!"

//  Defines for TMI's student base system
 
#define MAX_STUDENT_NUM		20
#define STUDENT_TIME_PERIOD	(60 * 86400)
 
//  Maxium commands can process in one heart beat

#define MAX_COMMAND_PER_HEART_BEAT	10
 
//  Mudlib definable locations
 
#define START		"/d/adventurer/hall/adv_guild"
#define VOID		"/d/std/rooms/void"

// define this if you have a pre-0.9.17.13 driver

#undef SIMUL_STRSRCH

// Note: some people may dislike the block_attack() system during combat...
// partly because it's inconsistently used (eg in 'say', but not in 'shout')
// in the mudlib, or because some players dislike this "feature".  *grin*
// If this applies to you (the sysadmin), #undef the next line

#define BLOCK_ATTACK 	1

// You can have the MUD keep track of which commands are being used and
// how much time they're taking by #defining PROFILING. This will take up
// a fair bit of CPU, so don't leave this on unless you have some use for
// the information - such as trying to find out where your MUD is slowing
// down - or you have CPU to blow (and who does?  ;)
// #define PROFILING 1

#endif /* __CONFIG_H */
