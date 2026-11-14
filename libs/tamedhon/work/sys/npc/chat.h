// SilberLand MUDlib
//
// sys/npc/chat.h -- NPC chats and attack chats
//
// $Date: 1997/03/31 14:33:24 $
/* $Revision: 1.1 $
 * $Log: chat.h,v $
 * Revision 1.1  1997/03/31 14:33:24  Woody
 * prepared for revision control
 *
 * Revision 1.0  1996/03/12  15:07:00  Mupfel
 * neu angelegt, defines aus /sys/properties.h,
 * prototypen aus /std/npc/chat.c
 *
 */
 
#ifndef __NPC_CHAT_H__
#define __NPC_CHAT_H__

// properties
#define P_CHATS "chats"
#define P_CHAT_CHANCE "chat_chance"
#define P_ACHATS "achats"
#define P_ACHAT_CHANCE "achat_chance"

#endif // __NPC_CHAT_H__

#ifdef NEED_PROTOTYPES

#ifndef __NPC_CHAT_H_PROTO__
#define __NPC_CHAT_H_PROTO__

// prototypes
void SetChats(int chance, mixed strs);
void SetAttackChats(int chance, mixed strs);
void DoAttackChat();
void DoChat();

#endif // __NPC_CHAT_H_PROTO__

#endif	// NEED_PROTOYPES
