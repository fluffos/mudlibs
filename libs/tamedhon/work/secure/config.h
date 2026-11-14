/* Tamedhon MUDLIB
 * config.h -- MUD basic configuration
 * 
 * 2024/06/21 - WL sefuns - Aloy
 * 2024/04/09 - Settings fuer Tame v2. LD simul_efuns - Aloy
 *
 * $Date: 2001/01/04 18:52:13 $
 * $Revision: 1.2 $
 * $Log: config.h,v $
 * Revision 1.2  2001/01/04 18:52:13  Samtpfote
 * Flag fuer TestMUD eingebaut, versch. Bereinigungen
 *
 * Revision 1.1  2001/01/04 16:21:14  Samtpfote
 * Initial revision
 *
 */
 

#ifndef _CONFIG_
#define _CONFIG_

#define NATIVE
#define NATIVE_MODE

#define TESTMUD 

#ifdef TESTMUD
#define MUDHOST "127.0.0.1"  
#define UDPSERV "127.0.0.1"
#define MUDNAME "TD-TEST@"+__HOST_NAME__

#else 

#define MUDHOST "127.0.0.1"
#define UDPSERV "127.0.0.1"
#define MUDNAME "TD-HOMEMUD"

#endif

//mysql connection settings
#define MYSQL_DATABASE  "tamedhon"
#define MYSQL_USER      "root"
#define MYSQL_PASSWORD  "mud"

// #define NAME_QUESTION "Wie lautet Dein Name (\"neu\" fuer neuen Spieler) ?  "

#define LIBVERSION "2.1"


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

#define UDP_ENCODING "UTF-8"

#define NETDEAD_ROOM "/room/netztot"
#define NETDEAD_CHECK_TIME 100 /* Check all 5 Minutes */

// Einstellungen fuer den IP-Namens Cache
#define IP_VALID_CACHE   86400 // Eintraege im IP-Name-Cache nach 24h erneuern
#define IP_RETRY      (3600*8) // Nichtgefundene Namen nach 8 Std nochmals
#define IP_INIT_RETRY      120 // Zunaechst 2x nach zwei Minuten nochmals

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
#define SIMUL_EFUN_FILE       "/secure/simul_efun"
#endif
#ifndef SPARE_SIMUL_EFUN_FILE
#define SPARE_SIMUL_EFUN_FILE "/secure/spare_simul_efun"
#endif

//#define CALL_OUT_INFO_DAMAGED 1

#endif
