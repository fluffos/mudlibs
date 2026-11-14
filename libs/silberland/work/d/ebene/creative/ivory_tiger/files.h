/*
  files.h
  
  Fuer die Gilde des elfenbeinernen Tigers.
*/

#ifndef __IVORY_TIGER_H__
#define __IVORY_TIGER_H__

#include <defines.h>
#include <moredef.h>

#define DEBUG(x,y) if (find_player("creative")) tell_object(find_player("creative"), "|**"+x+"**| "+y+"\n")

#define PATH "/d/ebene/creative/ivory_tiger/"
#define STD(x) PATH+"std/"+x
#define ROOM(x) PATH+"room/"+x
#define OBJ(x) PATH+"obj/"+x
#define NPC(x) PATH+"npc/"+x
#define LOG(x) PATH+"log/"+x
#define WEAPON(x) PATH+"weapon/"+x
#define ARMOUR(x) PATH+"armour/"+x

#define TIPO (this_interactive() || previous_object())

/*
#define CAP capitalize
#define TO this_object()
#define TP this_player()
#define PO previous_object()
#define TPN TP->QueryProp(P_NAME)
#define TI this_interactive()
#define BS(x) break_string(x, 78)
#define ENV environment
*/

#define P_ZONE "zone"
#define P_SUBDOMAIN "subdomain"
#define P_HELP_ROOMS "help_rooms"
#define P_HELPING "helping"
#define P_MAX_HELPERS "max_helpers"
#define P_HELPERS "helpers"
#define P_2ATTACK "2attack"
#define P_APPLIED_BALM "applied_balm"
#define P_MAY_WEAR_BALMED "may_wear_balmed"
#define P_IVORY "ivory_relevant"

#define UMSTR "/d/ebene/creative/ivory_tiger/std/umaster"

// #define KEYLOG "/d/ebene/creative/ivory_tiger/log/key.log"

#define KEYMASTER STD("keymaster")
#define WAYS STD("guildways")
#define THIEFMASTER STD("thiefmaster")
#define SWMASTER STD("swmaster")

#endif /* __IVORY_TIGER_H__ */
