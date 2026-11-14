/* Headerfile fuer den eigenen Standard-NPC.
 *
 *  (c) 1999 Adrian Holzwarth / Anatol@Silberland
 */

#ifndef _NACHT_NPC_H_
#define _NACHT_NPC_H_

// Ist diese Property im NPC gesetzt, antwortet er nicht mehr, verzichtet
// auch auf seine Room-Chats.

#define P_NPC_QUIET "npc_quiet"
#define QUIET_MSG 0
#define QUIET_FLAG 1
#ifdef NEED_PROTOTYPES
public varargs string name(int casus, int demon);
public varargs string Name(int casus, int demon);
public mixed InFight();
#endif
#endif

