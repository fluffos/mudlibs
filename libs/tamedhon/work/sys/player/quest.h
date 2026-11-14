// SilberLand MUDlib
//
// sys/player/quest.h -- player quest handler header
//
// $Date: 1997/03/31 15:16:21 $
/* $Revision: 1.4 $
 * $Log: quest.h,v $
 * Revision 1.4  1997/03/31 15:16:21  Woody
 * prepared for revision control; added prototype for DeleteQuest()
 *
 * Revision 1.3  1994/09/16  17:46:13  Jof
 * Changed prototype for GiveQuest
 *
 */
 
#ifndef __PLAYER_QUESTS_H__
#define __PLAYER_QUESTS_H__

// properties

#define P_QUESTS        "quests"
#define P_QP            "questpoints"

#endif // __PLAYER_QUESTS_H__

#ifdef NEED_PROTOTYPES

#ifndef __PLAYER_QUESTS_H_PROTO__
#define __PLAYER_QUESTS_H_PROTO__ 

// prototypes

varargs int GiveQuest(string questname, string message);
int DeleteQuest(string questname);
int QueryQuest(string questname);

#endif // __PLAYER_QUESTS_H_PROTO__

#endif // NEED_PROTOYPES
