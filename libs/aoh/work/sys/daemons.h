#ifndef _DAEMONS_
#define _DAEMONS_ 1

/*--------------------------------------------------------------------------
 * /sys/daemons.h -- Definition of standard daemons with symbolic names.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include "config.h"

// The country daemon to translate IPs into Cities and Countries.
#define COUNTRY_D    DAEMONPATH "country"

// The keyword server for the player's help command.
#define KEYWORD_D    DAEMONPATH "help/keyword_server"

// The server for an always-up-to-date mudlib version string.
#define LIBVERSION_D  DAEMONPATH "version"

// The intermud daemon
#define INET_D        DAEMONPATH "inetd"

// The mailer daemon - at /mail for uid reasons
#define MAILER_D      "/mail/mailer"

// The intermud mailer daemon - at /mail for uid reasons
#define INET_MAILER_D "/mail/inet_mailer"

// The intermud-3 daemons
#if 0
#define INET3_D       DAEMONPATH "inet3_d"
#endif
#define INET3_D       DAEMONPATH "i3d"

// The channel daemon, should be already defined at secure/config.h
#ifndef CHANNEL_D
#define CHANNEL_D     DAEMONPATH "channel_d"
#endif

// The dict daemon
#define DICT_D        DAEMONPATH "dict"

// The colour daemon
#define COLOUR_D      DAEMONPATH "colour_d"

// The bank daemon
#define BANK_D        DAEMONPATH "bank_d"

// The money daemon
#define MONEY_D       DAEMONPATH "money_d"

// The money log daemon (cashflow)
#define MONEYLOG_D    DAEMONPATH "moneylog_d"

// The testy daemon
#define TESTY_D       DAEMONPATH "testy_d"

// The toplist daemon
#define TOPLIST_D     DAEMONPATH "toplist_d"

// the quest daemon
#define QUEST_D       DAEMONPATH "quest_control"

// the explorer point daemon
#define EXPLORER_D    DAEMONPATH "explorer"

// the finger daemon
#define FINGER_D      "/std/player/bin/finger"
// the vote daemon .. should become VOTE_D if removed from secure/config
//#define VOTE_D        DAEMONPATH "voteserver"
#define VOTESERVER    DAEMONPATH "voteserver"

// the fortuen daemon
#define FORTUNE_D    DAEMONPATH "fortune_d"

// The man page daemon
#define MAN_D    DAEMONPATH "manserver"
#define MANBASE  DAEMONPATH "manbase"   // internal use only

// the more daemon
#define MORE             "/lib/more"


#endif /* _DAEMONS_ */
