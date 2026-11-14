

#pragma strong_types

#include <defines.h>
#include <moredef.h>

#define REGION "unterwelt"
#define APATH "/d/unterwelt/clementine/polaris/"
// #define APATH "/players/clementine/polaris/"
#define LOG(x) APATH "log/"+x
#define ROOM(x) APATH "room/"+x
#define OBJ(x) APATH "obj/"+x
#define NPC(x) APATH "npc/"+x
#define ARMOUR(x) APATH "armour/"+x
#define WEAPON(x) APATH "weapon/"+x
#define GESCHENK(x) APATH "geschenke/"+x
#define DB(x) if(find_player("clementine")) tell_object(find_player("clementine"), "\nXXX"+x+"\n")
#define WRITELOG(x) write_file(LOG("polaris.log"),ctime()+":"+x+".\n")
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())
#define ME this_object()
#define BS(x) break_string(x, 78)
#define WLOG(f,x) write_file(f,sprintf("%s  %s "+x+".\n",dtime(time()),TPN));
#define TELLOTHERS say(this_player()->Name() +
// #define SAVEFILE APATH "master/kills"
// #define KMASTER APATH "master/killmaster"


#define ANSCHLUSS_HUEGELLAND "/d/huegelland/feyaria/weg/room/1517"
#define ANSCHLUSS_DIMENSION "/d/unterwelt/amazora/dimension/room/dimens1"
#define ANSCHLUSS_UNTERWELT "/d/unterwelt/basics/central/room/gruft"

