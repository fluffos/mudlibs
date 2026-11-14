#ifndef _CONFIG_
#define _CONFIG_

/*
 * config.h
 *
 * general configuration is done here, the selection of gamedriver mode
 * and the language to use.
 */

#define MUDNAME "SilberLand"
#define TESTMUDNAME "TestSilber"
#define NAME_QUESTION "Wie heisst Du denn (\"neu\" fuer neuen Spieler) ?  "

#define MUDHOST "forest"
#define FTPD_IP "77.237.49.230"
#define UDPSERV "127.0.0.1"
#define LOCALHOST_IP "127.0.0.1"

#if (__HOST_NAME__!=MUDHOST)
#undef MUDNAME
#define MUDNAME TESTMUDNAME+"@"+__HOST_NAME__
#endif

#define NATIVE
#define NATIVE_MODE

#define DEUTSCH
/* define general pathnames */
#define MASTER "secure/master"
#define MAILPATH "mail/"
#define SAVEPATH "save/"
#define NEWSPATH "news/"
#define NEWSSERVER "secure/news"
#define SECURESAVEPATH "secure/save/"
#define COMBAT_MASTER "secure/combat"
#define WIZARDDIR "players"
#define DOMAINDIR "d"
#define PROJECTDIR "p"

#define NETDEAD_ROOM "/room/netztot"
#define NETDEAD_CHECK_TIME 5

/* define special userids */ 
#define BACKBONEID " S T D "
#define ROOTID " R O O T "			/* uppercase !! */
#define MAILID " M A I L "
#define NEWSID " N E W S "

#define MAX_LOG_SIZE 50000

#ifndef TESTMUD
#define CALL_OUT_HARD 1200
#define CALL_OUT_SOFT 1000
#else
#ifdef MIN_CALL_OUT
#define CALL_OUT_HARD 120
#define CALL_OUT_SOFT 100
#else
#define CALL_OUT_HARD 120000
#define CALL_OUT_SOFT 100000
#endif
#endif

#define BACKBONE_WIZINFO_SIZE 8
#define LIVING_NAME 3
#define NAME_LIVING 4
#define LAST_REBOOT 5
#define NETDEAD_MAP 6
#define IP_NAMES	7

#ifndef SIMUL_EFUN_FILE
#define SIMUL_EFUN_FILE       "secure/simul_efun"
#endif
#ifndef SPARE_SIMUL_EFUN_FILE
#define SPARE_SIMUL_EFUN_FILE "secure/spare_simul_efun"
#endif
#ifndef SOCKETD_FILE
#define SOCKETD_FILE "p/daemon/socketd"
#endif

//#define CALL_OUT_INFO_DAMAGED 1
//#define RESET_PROFILING

#endif
