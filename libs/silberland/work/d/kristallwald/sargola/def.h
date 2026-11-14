#ifndef MAGIERNAME
#define MAGIERNAME "sargola"
#endif
#include "../def.h"

#define ROOM_SEHER "/d/kristallwald/sargola/seher/room/"

#define ELESSARELF "\nelessar_elf"
#define WMASTER NPC "wmaster"

#define KLOG "/d/kristallwald/sargola/log/"

#define wr(a) printf("%O\n",a);

// by PROtheG 
#define PRO(x) if (find_player("protheg")) tell_object(find_player("protheg"), BS(x))

#define CLOSURE(x) #'x
