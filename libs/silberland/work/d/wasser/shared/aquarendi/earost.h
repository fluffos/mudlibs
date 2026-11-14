//earost.h

#include "../water.h"

#ifndef EAROSTHOME
#undef EAROSTHOME
#endif
#define EAROSTHOME WHOME+"/earost"

#ifdef OBJ
#undef OBJ
#endif
#define OBJ EAROSTHOME+"/obj"

#ifdef ROOM
#undef ROOM
#endif
#define ROOM EAROSTHOME+"/room"

#ifndef NPC
#undef NPC
#endif
#define NPC EAROSTHOME+"/npc"

#ifndef LOG
#undef LOG
#endif
#define LOG EAROSTHOME+"/log"

#ifndef WEAPON
#undef WEAPON
#endif
#define WEAPON EAROSTHOME+"/weapon"

#ifndef ARMOUR
#undef ARMOUR
#endif
#define ARMOUR EAROSTHOME+"/armour"
