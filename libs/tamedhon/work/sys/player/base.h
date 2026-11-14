// Tamedhon MUDlib
//
// sys/player/base.h -- player base header
//
// $Date: 2012/04/01 15:00:00 $
/* $Revision: 2.6 $
 * $Log: base.h,v $
 *
 * Revision 2.6  2012/04/01 15:00:00  Rommy
 * P_NO_ASCII_ART eingefuehrt
 *
 * Revision 2.5  2008/03/21 14:00:00  TamTam
 * CAN_ERZ eingefuehrt
 *
 * Revision 2.4  2006/11/18 23:28:00  Serii
 * P_MAILADDR_INVIS eingefuehrt
 *
 * Revision 2.6  2006/11/18 00:00:00  Gralkor
 * P_SECOND_INVIS eingefuegt (s. manpage)
 * 2006-11-18 Gralkor
 *
 * Revision 2.5  2005/11/05 19:20:00  Querolin
 * P_WEBMAIL_ALLOWED eingefuegt
 *
 * Revision 2.4  2005/07/05 17:50:00  Querolin
 * P_LAST_ADVANCE und P_LAST_ADVANCE_GUILD eingefuegt
 *
 * Revision 2.3  2003/12/27 16:36:39  Falgrim
 * temporaere funktion _query_color & _query_colorI
 *
 * Revision 2.2  2001/06/04 16:36:39  Querolin
 * P_ICQ und P_HOMEPAGE fuer finger eingebaut
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

#include "/sys/player/telnetneg.h"
#include "/sys/player/can.h"

// noch keine autom. Seherhaeuser im SL
// #define HAUSVERWALTER        "/d/seher/wargon/haeuser/hausverwalter"

// Homepage fuer 'finger'
#define P_HOMEPAGE "p_homepage"

//Webmail
#define P_WEBMAIL_ALLOWED "webmail_allowed"

// Wann wurde die letzte Stufe erhoeht bzw der letze Gildenlevel?
#define P_LAST_ADVANCE_GUILD "last_advance_guild"
#define P_LAST_ADVANCE "last_advance"

// properties

#define P_LOGON_PLACE		"logon_place"
#define P_CREATION_DATE         "creation_date"
#define P_LAST_LOGIN            "last_login"
#define P_LAST_LOGOUT           "last_logout"
#define P_IGNORE                "ignore"
#define P_SHOW_EXITS            "show_exits"
#define P_WANTS_TO_LEARN        "wants_to_learn"
#define P_AUTOLOADOBJ           "autoloadobj"
#define P_AUTOLOAD              "autoload"
#define P_LAST_ROOM             "last_room"
#define P_ARMOURS_SAVE          "armours_save"
#define P_WEAPON_SAVE           "weapon_save"

// email addresse sichtbar fuer spieler?
#define P_MAILADDR_INVIS	"email_invis"
#define P_MAILADDR              "mailaddr"

#define P_FOLLOW_SILENT         "follow_silent"

#define P_INVIS                 "invis"

#define P_SECOND                "second"
#define P_SECOND_INVIS		"second_invis"
#define P_TESTPLAYER            "testplayer"

#define P_START_HOME            "start_home"
#define P_LAST_AWAKE_TIME       "last_awake_time"
#define P_LAST_DEATH_SEQUENCES  "last_death_sequences"

#define P_CMSG                  "clonemsg"
#define P_DMSG                  "destmsg"
#define P_CLONE_MSG             "clone_msg"
#define P_DESTRUCT_MSG          "destruct_msg"

#define P_PROMPT                "prompt"
#define P_SCREENSIZE            "screensize"
#define P_MORE_FLAGS            "more_flags"
#define P_NO_ASCII_ART          "no_ascii_art"

#define P_READ_NEWS             "read_news"

#define P_NEEDED_QP             "needed_qp"

#endif // __PLAYER_BASE_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_BASE_H_PROTO__
#define __PLAYER_BASE_H_PROTO__

// prototypes

void smart_log(string myname, string str);
int QueryGuest();
int invis();
int vis();

varargs nosave void stop_heart_beats(mixed obs);
nosave void restart_heart_beats();

void save_me(mixed value_items);

string _query_color(object ob, string str);
string _query_colorI(string str);
nomask mixed query_real_name();

public object|object* QueryArmourByType(string type);

#endif // __PLAYER_BASE_H_PROTO__

#endif // NEED_PROTOYPES
