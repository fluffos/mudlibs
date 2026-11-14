// SilberLand MUDlib
//
// std/npc/chat.c -- NPC chat functions
//
// $Date: 1997/03/14 14:04:58 $
/* $Revision: 1.2 $
 * $Log: chat.c,v $
 * Revision 1.2  1997/03/14 14:04:58  Woody
 * Existenz von this_object() in Do(Attack)Chat() pruefen
 *
 * Revision 1.1  1997/03/13 01:13:06  Woody
 * prepared for revision control
 *
 * modified 1996/03/12 15:02:00 by Mupfel
 */

#include <properties.h>
#define NEED_PROTOTYPES
#include <living/combat.h>
#include <thing/properties.h>
#undef NEED_PROTOTYPES

#define ME this_object()

void DoAttackChat();
void DoChat();

/*
 * Some simple chat variables
 */

/*
 * heart_beat is called so the monster may chat.
 */
void heart_beat()
{
  if( InFight() ) DoAttackChat();
  else            DoChat();
}

void SetChats(int chance, mixed strs) {
  if (!pointerp(strs))
    return;
  SetProp(P_CHAT_CHANCE,chance);
  SetProp(P_CHATS,strs);
}

void SetAttackChats(int chance, mixed strs) {
  if (!pointerp(strs))
    return;
  SetProp(P_ACHAT_CHANCE,chance);
  SetProp(P_ACHATS,strs);
}

void DoAttackChat() {
  string* c;
  if (!ME || !environment(ME))
    return;
  if (random(100) < QueryProp(P_ACHAT_CHANCE))
    if ((c = QueryProp(P_ACHATS)) && sizeof(c)) 
      tell_room(environment(ME),
		process_string(c[random(sizeof(c))]));
}

void DoChat() {
  string *c;
  if (!ME || !environment(ME))
    return;
  if (random(100) < QueryProp(P_CHAT_CHANCE))
    if ((c = QueryProp(P_CHATS)) && sizeof(c)) 
      tell_room(environment(ME),
		process_string(c[random(sizeof(c))]));
}
