// SilberLand MUDlib
//
// sys/player/base.h -- player base header
//
// $Date: 2017/04/19 07:52:59 $
/* $Revision: 2.18 $
 * $Log: base.h,v $
 * Revision 2.18  2017/04/19 07:52:59  Woody
 * added P_NO_ASCII_ART
 *
 * Revision 2.17  2004/04/21 20:10:34  Feyaria
 * P_LAST_DEATH_SEQUENCES
 *
 * Revision 2.16  2004/03/03 09:59:47  Feyaria
 * P_SCREENWIDTH
 *
 * Revision 2.15  2003/12/22 13:17:34  Angrox
 * P_LAST_DIE_TIME hinzugefuegt
 *
 * Revision 2.14  2003/11/10 14:23:09  Woody
 * von properties.h verschoben: P_LOOTING
 *
 * Revision 2.13  2003/11/02 10:38:57  Angrox
 * P_LAST_DIE_TIME hinzugefuegt
 *
 * Revision 2.12  2003/10/06 14:21:01  Cirion
 * P_MESSENGER hinzugefuegt
 *
 * Revision 2.11  2003/08/05 10:38:40  Woody
 * neu: P_LOCATION
 *
 * Revision 2.10  2002/10/10 18:08:56  Woody
 * P_INFORMME, P_WAITFOR, P_CLOCKMSG verlegt, neu: P_SECOND_MARK, P_SHOW_EMAIL
 *
 * Revision 2.9  2002/01/29 15:55:10  Woody
 * Prototypes fuer invis() und vis() updated
 *
 * Revision 2.8  2000/07/01 21:28:55  Zordan
 * IF_SHOWCLONES eingefuehrt
 *
 * Revision 2.7  2000/03/05 16:43:29  Zordan
 * IF_INFORMME, IF_SHOWIP, IF_SHOWRACE definiert fuer Inform
 *
 * Revision 2.6  2000/01/09 19:59:16  Zordan
 * P_ICQ
 *
 * Revision 2.5  1998/09/20 15:19:55  Woody
 * P_HOMEPAGE, P_NO_TOPLIST
 *
 * Revision 2.4  1998/07/31 12:30:08  Woody
 * P_LAST_VISIBLE_LOGOUT
 *
 * Revision 2.3  1998/06/19 10:57:21  Angrox
 * P_TMP_PRAY_ROOM added
 *
 * Revision 2.2  1997/11/05 16:36:39  Woody
 * P_LAST_AWAKE_TIME, P_MORE_FLAGS
 *
 * Revision 2.1  1997/06/25 12:16:18  Woody
 * CAN_PRESAY definiert
 *
 * Revision 2.0  1997/03/31 14:58:11  Woody
 * prepared for revision control; removed P_FLAGS
 *
 * Revision 1.15  1996/09/22  02:00:00  Woody
 * P_CREATION_DATE
 *
 * Revision 1.14  1995/05/10  09:19:07  Rumata
 * P_CMSG -> P_CLONE_MSG, P_DMSG -> P_DESTRUCT_MSG
 *
 * Revision 1.13  1995/05/09  20:31:24  Hate
 * added P_CMSG and P_DMSG
 *
 * Revision 1.12  1995/02/02  18:56:57  Jof
 * P_READ_NEWS
 *
 * Revision 1.11  1994/11/30  01:02:40  Kirk
 * P_LAST_LOGIN / P_LAST_LOGOUT
 *
 * Revision 1.10  1994/11/30  00:43:31  Kirk
 * CAN_FLAGS
 *
 * Revision 1.9  1994/10/18  09:29:02  Jof
 * wargons aenderungen
 *
 * Revision 1.8  1994/10/17  17:41:01  Boing
 * P_SECOND eingebaut
 *
 * Revision 1.7  1994/08/24  18:42:41  Jof
 * *** empty log message ***
 *
 * Revision 1.6  1994/02/09  15:57:04  Jof
 * defined HAUSVERWALTER
 *
 * Revision 1.5  1994/01/26  14:09:58  parse
 * *** empty log message ***
 *
 * Revision 1.4  1994/01/25  11:14:48  jof
 * follow_silent
 *
 * Revision 1.3  1994/01/19  20:26:36  mud
 * *** empty log message ***
 *
 * Revision 1.2  1994/01/18  01:06:32  mud
 * *** empty log message ***
 *
 * Revision 1.1  1994/01/06  10:46:59  mud
 * Initial revision
 *
 */

#ifndef __PLAYER_BASE_H__
#define __PLAYER_BASE_H__

// noch keine autom. Seherhaeuser im SL
// #define HAUSVERWALTER        "/d/seher/wargon/haeuser/hausverwalter"

// properties

#define P_CREATION_DATE         "creation_date"
#define P_LAST_LOGIN            "last_login"
#define P_LAST_LOGOUT           "last_logout"
#define P_LAST_VISIBLE_LOGOUT   "last_visible_logout"

#define P_IGNORE                "ignore"
#define P_SHOW_EXITS            "show_exits"
#define P_WANTS_TO_LEARN        "wants_to_learn"
#define P_AUTOLOADOBJ           "autoloadobj"
#define P_AUTOLOAD              "autoload"

#define P_TTY                   "tty"
#define P_SECOND                "second"
#define P_SECOND_MARK           "second_mark"
#define P_TESTPLAYER            "testplayer"
#define P_NO_TOPLIST            "no_toplist"
#define P_INFORMME              "informme"
#define P_WAITFOR               "waitfor"
#define P_CLOCKMSG              "clockmsg"
#define P_LOOTING               "looting"

#define P_MAILADDR              "mailaddr"
#define P_HOMEPAGE              "homepage"
#define P_ICQ                   "icq"
#define P_MESSENGER             "messenger"
#define P_LOCATION              "location"
#define P_SHOW_EMAIL            "show_email"

#define P_INVIS                 "invis"
#define P_FOLLOW_SILENT         "follow_silent"

#define P_START_HOME            "start_home"
#define P_TMP_PRAY_ROOM         "tmp_pray_room"
#define P_LAST_AWAKE_TIME       "last_awake_time"
#define P_LAST_DIE_TIME         "last_die_time"
#define P_LAST_CORPSE           "last_corpse"
#define P_LAST_DEATH_SEQUENCES  "last_death_sequences"
 
#define P_CMSG                  "clonemsg"
#define P_DMSG                  "destmsg"
#define P_CLONE_MSG             "clone_msg"
#define P_DESTRUCT_MSG          "destruct_msg"

#define P_CARRIED_VALUE         "carried"

#define P_PROMPT                "prompt"
#define P_SCREENSIZE            "screensize"
#define P_SCREENWIDTH           "screenwidth"
#define P_MORE_FLAGS            "more_flags"

#define P_NO_ASCII_ART          "no_ascii_art"

#define P_CAN_FLAGS             "can_flags"

#define P_READ_NEWS             "read_news"

// Inform Flags
#define IF_INFORMME     0x01
#define IF_SHOWIP       0x02
#define IF_SHOWRACE     0x04
#define IF_SHOWCLONES   0x08

// bitmasks
#define CAN_EMOTE  0x01
#define CAN_ECHO   0x02
#define CAN_REMOTE 0x04
#define CAN_PRESAY 0x08

#define P_NEEDED_QP             "needed_qp"

#endif // __PLAYER_BASE_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_BASE_H_PROTO__
#define __PLAYER_BASE_H_PROTO__

// prototypes

void smart_log(string myname, string str);
int QueryGuest();
int invis(string str);
int vis(string str);

varargs nosave void stop_heart_beats(mixed obs);
nosave void restart_heart_beats();

void save_me(mixed value_items);

#endif // __PLAYER_BASE_H_PROTO__

#endif // NEED_PROTOYPES
