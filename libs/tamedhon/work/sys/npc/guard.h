// SilberLand MUDlib
//
// sys/npc/guard.h -- restrictions for guard NPCs
//
// $Date: 1997/03/31 14:41:12 $
/* $Revision: 1.1 $
 * $Log: guard.h,v $
 * Revision 1.1  1997/03/31 14:41:12  Woody
 * prepared for revision control
 *
 * Revision 1.0  1996/03/12  15:10:00  Mupfel
 * uebernommen aus /sys/guard.h, mit prototypen aus /std/npc/guard.c
 *
 */
 
#ifndef __NPC_GUARD_H__
#define __NPC_GUARD_H__

// properties
#define P_GUARD "guard"

#define GUARD_QUEST 0x0001
// bewacht Questobjekt
#define GUARD_POTION 0x0002
// bewacht Zaubertrank
#define GUARD_PERSON 0x0004
// bewacht Person, i.A. NPC
#define GUARD_THING 0x0008
// bewacht Gegenstand von irgend einem Wert
#define GUARD_LOCATION 0x0010
// bewacht Ort

#endif // __NPC_GUARD_H__

#ifdef NEED_PROTOTYPES

#ifndef __NPC_GUARD_H_PROTO__
#define __NPC_GUARD_H_PROTO__

// prototypes
varargs mixed SetGuardProtection(int strength, int types);
varargs int QueryGuardProtection(int arg);

#endif // __NPC_GUARD_H_PROTO__

#endif	// NEED_PROTOYPES
