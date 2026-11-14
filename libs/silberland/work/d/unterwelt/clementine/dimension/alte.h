
#pragma strong_types

#include <defines.h>
#include <moredef.h>

#define REGION "unterwelt"
#define APATH "/d/unterwelt/clementine/dimension/"
#define ROOM APATH "room/"
#define WEG APATH "weg/"
#define OBJ APATH "obj/"
#define NPC APATH "npc/"
#define LOG APATH "log/"
#define ARMOUR APATH "armour/"
#define WEAPON APATH "weapon/"
#define ME this_object()
#define BS(x) break_string(x, 78)
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
#define TELLOTHERS say(this_player()->Name() +
#define CTPN capitalize(this_player()->name())
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())
#define WRITELOG(x) write_file(LOG("dimension.log"),ctime()+":"+x+".\n")
	
