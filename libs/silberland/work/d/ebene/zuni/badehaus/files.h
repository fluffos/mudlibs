/*

 files.h

 Erstellt  : 05. August 2000 (Roc akn@fast.de)
 Geaendert : 05.08.00 22:05  (Roc akn@fast.de)
 angepasst : 13.09.2000 (zuni)
 angepasst : 21.08.2002
 angepasst : 28.04.2004
*/

#pragma strong_types
#define DEBUG(x,y) if (find_player("zuni")) tell_object(find_player("zuni"), "|**"+x+"**| "+y+"\n")

#include <defines.h>
#include <moredef.h>

#define PATH "/d/ebene/zuni/badehaus/"
#define STD     PATH "std/"
#define ROOM    PATH "room/"
#define ITEM    PATH "obj/"
#define NPC     PATH "npc/"
#define NEWS    PATH "news/"
#define LOG     PATH "log/"
#define WEAPON  PATH "weapon/"
#define ARMOUR  PATH "armour/"



