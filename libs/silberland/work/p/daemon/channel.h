// SilberLand MUDlib
//
// /p/daemon/channel.h -- channel daemon defines
//
// $Date: 2004/06/25 07:32:06 $
/* $Revision: 1.7 $
 * $Log: channel.h,v $
 * Revision 1.7  2004/06/25 07:32:06  Cirion
 * Definition fuer Maximallaenge von Channelnamen (MAX_CHANNELNAME_LEN)
 *
 * Revision 1.6  2003/10/02 18:38:53  Woody
 * Defines von channeld.c herverlegt: CMNAME, CHANNEL_SAVE, MAX_*
 *
 * Revision 1.5  2001/02/01 23:51:40  Woody
 * #endif syntax bugfixed
 *
 * Revision 1.4  2000/01/08 18:09:49  Zordan
 * C_REVEICE als Bann Kommando fuer channeld
 *
 * Revision 1.3  1998/09/20 13:09:25  Woody
 * Neuer channeld
 *
 * Revision 1.2  1997/03/16 02:19:39  Woody
 * prepared for revision control
 *
 * Revision 1.1a 1996/04/17  13:20:00  Woody
 * Kosten auf 1 MP gesenkt
 *
 * Revision 1.1  1995/03/31  13:30:33  Hate
 * Initial revision
 *
 */

#ifndef __CHANNEL_H__
#define __CHANNEL_H__

// properties
#define P_CHANNELS              "channels"
#define P_STD_CHANNEL           "std_channel"

// The master itself
#define CHMASTER                "/p/daemon/channeld"
#define VOICEMASTER CHMASTER

// Name of master channel
#define CMNAME  "<MasteR>"
#define CHANNEL_SAVE    "/p/daemon/save/channeld"

// Maximum history size and number of channels
#define MAX_HIST_SIZE           60
#define MAX_CHANNELS            75

// Maximum channel name length
#define MAX_CHANNELNAME_LEN     30

// Message types
#define MSG_SAY                 0
#define MSG_EMOTE               1
#define MSG_GEMOTE              2
#define MSG_EMPTY               3
#define SAY                     MSG_SAY
#define EMOTE                   MSG_EMOTE
#define GEMOTE                  MSG_GEMOTE
#define EMPTY                   MSG_EMPTY

// Errors
#define E_ACCESS_DENIED         -1
#define E_ALREADY_JOINED        -2
#define E_NOT_MEMBER            -3
#define E_EMPTY_MESSAGE         -4
#define E_UNKNOWN_TYPE          -5

// Commands
#define C_NEW                   "new"
#define C_JOIN                  "join"
#define C_LEAVE                 "leave"
#define C_SEND                  "send"
#define C_LIST                  "list"
#define C_FIND                  "find"
#define C_RECEIVE               "receive"

// definition of the list mapping entry
// ([ channelname : ({ I_MEMBER, I_ACCESS, I_INFO, I_MASTER, I_NAME }) ])
#define I_MEMBER                0
#define I_ACCESS                1
#define I_INFO                  2
#define I_MASTER                3
#define I_NAME                  4
#define I_TIMEOUT               5

#endif // __CHANNEL_H__

// prototypes
#ifdef NEED_PROTOTYPES

#ifndef __CHANNEL_H_PROTO__
#define __CHANNEL_H_PROTO__

varargs int new(string ch, mixed pl, mixed info);
int join(string ch, mixed pl);
int leave(string ch, mixed pl);
varargs int send(string ch, mixed pl, string msg, int type);
mixed list(mixed pl);
varargs int SendToChannel(string channel, object user, int cmd, string msg);

#endif // __CHANNEL_H_PROTO__

#endif // NEED_PROTOTYPES

