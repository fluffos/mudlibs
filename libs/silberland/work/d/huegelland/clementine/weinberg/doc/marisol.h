#pragma strong_types

#include <defines.h>
#include <moredef.h>

#define REGION "ebene"
//#define APATH "/d/ebene/clementine/max"
#define APATH "/players/clementine/max/"
#define LOG(x) APATH "log/"+x
#define ROOM(x) APATH "room/"+x
#define OBJ(x) APATH "obj/"+x
#define NPC(x) APATH "npc/"+x
#define ARMOUR(x) APATH "armour/"+x
#define WEAPON(x) APATH "weapon/"+x
#define DB(x) if(find_player("clementine")) tell_object(find_player("clementine"), "\nXXX"+x+"\n")
#define WRITELOG(x) write_file(LOG("max.log"),ctime()+":"+x+".\n")
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())

#define ME this_object()
#define BS(x) break_string(x, 78)
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));


