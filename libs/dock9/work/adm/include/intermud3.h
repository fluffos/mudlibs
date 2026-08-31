/*
 * intermud3.h
 *
 * Tricky@Rock the Halo
 * 17-AUG-2006
 * Intermud3 include file
 *
 * Last edited on November 12th, 2007 by Tricky
 *
 */

#ifndef __INTERMUD3_H__
#define __INTERMUD3_H__

#define INTERMUD_VER     "3"
#define INTERMUD_REV     "3"
#define INTERMUD_PATCH   (lib_version())

#define MIN_RETRY_TIME   30
#define MAX_RETRY_TIME   600
#define RETRY_TIME_STEP  20

#ifndef LOG_I3
#define LOG_I3           "i3.log"
#endif

#ifndef LOG_OOB
#define LOG_OOB          "oob.log"
#endif

#define I3LOG(s,o,f,m)   log_file(LOG_I3, s + " [" + o + "/" + f + "]: " + m + "\n")
#define OOBLOG(m)        log_file(LOG_OOB, m)

#define I3_MUD_NAME      (mud_name())

#define I3_DIR           "/adm/daemons/chmodules"
#define I3_SERVICES_DIR  (I3_DIR + "/i3services")

#ifndef I3_CHDMOD
#define I3_CHDMOD        (I3_DIR + "/chdmod_i3")
#endif

/* I3 services */
#define I3_AUTH          (I3_SERVICES_DIR + "/mod_auth")
#define I3_BEEP          (I3_SERVICES_DIR + "/mod_beep")
#define I3_CHANNEL       (I3_SERVICES_DIR + "/mod_channel")
#define I3_EMOTE         (I3_SERVICES_DIR + "/mod_emoteto")
#define I3_ERROR         (I3_SERVICES_DIR + "/mod_error")
#define I3_MUDLIST       (I3_SERVICES_DIR + "/mod_mudlist")
#define I3_OOB           (I3_SERVICES_DIR + "/mod_oob")
#define I3_PING          (I3_SERVICES_DIR + "/mod_ping")
#define I3_TELL          (I3_SERVICES_DIR + "/mod_tell")
#define I3_UCACHE        (I3_SERVICES_DIR + "/mod_ucache")
#define I3_WHO           (I3_SERVICES_DIR + "/mod_who")

/* Out Of Band */
#ifndef OOB_TCP_PORT
#define OOB_TCP_PORT     (port() + 5)
#endif

#define OOB_DIR          "/ftp/oob/"
#define OOB_FILE         (I3_SERVICES_DIR + "/oob_mod_file")

/* Intermud 3 data file location */
#define I3_DATA_FILE     "/data/daemons/chmodules/i3"

/* Intermud 3 chanlist file location */
#define I3_CHANLIST_FILE "/data/daemons/chmodules/i3.chanlist"

/* Intermud 3 mudlist file location */
#define I3_MUDLIST_FILE  "/data/daemons/chmodules/i3.mudlist"

/* Intermud 3 emote file location */
#define I3_EMOTE_FILE    "/data/daemons/chmodules/i3.emote"

/* Intermud 3 tell file location */
#define I3_TELL_FILE     "/data/daemons/chmodules/i3.tell"

/* Intermud 3 ucache file location */
#define I3_UCACHE_FILE   "/data/daemons/chmodules/i3.ucache"

/* How many line of history for each channel to keep */
#define HISTORY_SIZE     500

/* The base directory for the channel histories
   Each channel has it's own file */
#define HISTORY_DIR      "/data/daemons/chmodules/i3_history"

/* Index file for the channels */
#define CHANINDEX_FILE   "/data/daemons/chmodules/chanindex"

/* The base I3 packet */
#define I3_TYPE            0  /* name of requested service type */
#define I3_TTL             1  /* ttl */
#define I3_O_MUD           2  /* originator mudname */
#define I3_O_USER          3  /* originator username */
#define I3_T_MUD           4  /* target mudname */
#define I3_T_USER          5  /* target username */

/* ucache */
#define I3_UC_VISNAME      0
#define I3_UC_GENDER       1
#define I3_UC_LASTUPDATE   2
#define I3_UC_LASTACTIVE   3

/* mudlist */
#define I3_ML_STATE        0
#define I3_ML_IP_ADDR      1
#define I3_ML_PLAYER_PORT  2
#define I3_ML_OOB_TCP_PORT 3
#define I3_ML_OOB_UDP_PORT 4
#define I3_ML_MUDLIB       5
#define I3_ML_BASELIB      6
#define I3_ML_DRIVER       7
#define I3_ML_MUD_TYPE     8
#define I3_ML_OPEN_STATUS  9
#define I3_ML_ADMIN_EMAIL  10
#define I3_ML_SERVICES     11
#define I3_ML_OTHER_DATA   12

#endif /* INTERMUD3_H */
