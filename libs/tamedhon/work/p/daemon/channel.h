// SilberLand MUDlib
//
// /p/daemon/channel.h -- channel header
//
// $Date: 1997/03/16 02:19:39 $
/* $Revision: 1.2 $
 * $Log: channel.h,v $
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

// defines
#define VOICEMASTER     "/p/daemon/channeld"

#define EMPTY           0x0000
#define SAY             0x0001
#define EMOTE           0x0002
#define GEMOTE          0x0004
#define LOCK            0x0008
#define NEVER_LOCK      0x0010

#define USAGE_COST      1

// properties
#define P_CHANNELS      "channels"
#define P_STD_CHANNEL   "std_channel"

#endif // __CHANNEL_H__

#ifdef NEED_PROTOTYPES

#ifndef __CHANNEL_H_PROTO__
#define __CHANNEL_H_PROTO__

// prototypes
int RegisterUser(object user);
varargs int RemoveUser(object user,int channeld);
varargs string RegisterChannel(string channel, object user, int aflag);
varargs string RemoveChannel(string channel, object user, int aflag,int channeld,int urem);

varargs int ListChannels(object user);
int ListUsers(string channel, object user);

varargs int SendToChannel(string channel, object user, int command, string msg, int f_col);

#endif // __CHANNEL_H_PROTO__

#endif  // NEED_PROTOYPES

