#ifndef _SECURE_CONFIG_
#define _SECURE_CONFIG_ 1

/*--------------------------------------------------------------------------
 * /sys/secure/config.h -- Mudlib configuration parameters.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include "/sys/secure/version.h"
#include "/sys/secure/ports.h"

/* The hostname (as returned from query_host_name()) of the system
 * the _real_ OSB is running on. It is used to distinguish the
 * real OSB from clones.
 */
#define MUDHOST "aoh"

/* Important: the email address of the muds maintainer! */
#define GAMESMGR "ralph@zitz.dk"

/* The Muds name.
 * MUDNAME is the full name, MUDSHORT an abbreviation.
 */

#define MUDNAME  "AgeOfHeroes"
#define MUDSHORT "AoH"

/* Define default LPC statements to be incorporated into _every_ program here.
 * These are:
 *   #pragma combine_strings
 *   #pragma verbose_errors
 *   #define NIGHTFALL 2
 *   #define ONESTEPBEYOND 0
 *   #include "/sys/secure/config.h"
 *   #include "/sys/config.h"
 */
#if __VERSION__ > "3.5.0"
/* #define AUTO_INCLUDE_STRING "#pragma pedantic\n#pragma save_types\n#pragma rtt_checks\n#pragma range_check\n#define NIGHTFALL 2\n#define ONESTEPBEYOND 0\n#include \"/sys/secure/config.h\"\n#include "config.h"\n" */
#define AUTO_INCLUDE_STRING "#pragma strict_types\n#pragma pedantic\n#pragma save_types\n#pragma rtt_checks\n#pragma range_check\n#pragma warn_unused_variables\n#define NIGHTFALL 2\n#define ONESTEPBEYOND 0\n#include \"/sys/secure/config.h\"\n#include "config.h"\n"
#else
#define AUTO_INCLUDE_STRING "#define NIGHTFALL 2\n#define ONESTEPBEYOND 0\n#include \"/sys/secure/config.h\"\n#include "config.h"\n"
#endif

/* Standard objects */
#define MASTER        "/secure/master"
#define LOGIN         "/secure/login"
#define KERNEL        "/secure/kernel"
#define SPAREKERNEL   "/secure/sparekernel"
#define USERINFO      "/secure/info"
#define VOTE_D        "/secure/voted"
#define MAILDEMON     "/mail/mailer"
#define NEWSSERVER    "/news/master"
#define RACEMASTER    "/p/daemons/races/racemaster"
#define QUESTMASTER   "/p/daemons/quest_control"
#define CHANNEL_D     "/p/daemons/channel_d"
#define CHANNELMASTER "/p/daemons/channel_d"
#define SKILLMASTER   "/p/daemons/skillmaster"
#define EXPLOREMASTER "/p/daemons/explorer"
#define GAMECLOCK     "/p/daemons/gameclock"
#define SHUTDEMON     "/secure/shut"
#define MWHOD_DAEMON  "/secure/net/mwhod"
#define VOID          "/std/void"
#define NETDEATH      "/room/netdeath"

/* Standard paths */
#define MAILPATH       "/mail/"
#define NEWSGROUPS     "/news/"
#define SAVEPATH       "/save/players/"
#define NEWSPATH       "/news/"
#define SECUREPATH     "/secure/"
#define SECURESAVEPATH "/secure/save/"
#define BANISHPATH     "/secure/banish/"
#define DAEMONPATH     "/p/daemons/"
#define DAEMONSAVEPATH "/save/daemons/"
#define WPATH          "/players/"
#define DPATH          "/d/"
#define PPATH          "/p/"

/* The xDIR defines are used for filename analyses and mustn't contain
 * slashes.
 */
#define WDIR      "players"
#define DDIR      "d"
#define PDIR      "p"
#define SECUREDIR "secure"

/* Properties used by root objects
 */
#define SP_VMASTER         "VMaster"
#define SP_LAST_RESET      "LastRest"
#define SP_RESET_INTERVAL  "ResetInterval"

/* UDP-Port services */
#define UDP_HEADER  "/sys/secure/udp.h" // includes #define INETD

/* Define FTPD_ID to activate mudftp */
#if   __HOST_NAME__ == "helios"
#define FTPD_IP "134.169.34.13"
#elif __HOST_NAME__ == "kastor"
#define FTPD_IP "134.169.34.8"
#elif __HOST_NAME__ == "eos"
#define FTPD_IP "134.169.34.14"
#elif __HOST_NAME__ == "leander"
#define FTPD_IP "192.124.28.80"
#elif __HOST_NAME__ == "aquarius"
#define FTPD_IP "208.20.1.203"
#endif

/* define special userids */
#define BACKBONEID "std"
#define ROOTID     "ze/us"

/* decomment as you wish: */
#define LOG_KILLS

/* Adjust local time */
#define TIME_DELTA 7200

#endif /* _SECURE_CONFIG_ */
