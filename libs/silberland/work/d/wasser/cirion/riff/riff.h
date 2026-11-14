//riff.h

#include "/d/wasser/cirion/water.h"

#ifndef RIFFHOME
#undef RIFFHOME
#endif
#define RIFFHOME WHOME+"/riff"

#ifdef OBJ
#undef OBJ
#endif
#define OBJ RIFFHOME+"/obj"

#ifdef ROOM
#undef ROOM
#endif
#define ROOM RIFFHOME+"/room"

#ifndef NPC
#undef NPC
#endif
#define NPC RIFFHOME+"/npc"

#ifndef LOG
#undef LOG
#endif
#define LOG RIFFHOME+"/log"

#ifndef WEAPON
#undef WEAPON
#endif
#define WEAPON RIFFHOME+"/weapon"

#ifndef ARMOUR
#undef ARMOUR
#endif
#define ARMOUR RIFFHOME+"/armour"

#define RIFFQUESTNAME "Das geheimnisvolle Amulett"
#define QUESTOBID "\nciritabarquestob"
#define TABARID "\nciritabar"
#define RIFFQUESTLOGFILE LOG"/riffquest.log"