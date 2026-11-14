#pragma strong_types

#include <defines.h>
#include <moredef.h>

#define MAGIERNAME "clementine"
#define REGION "kristallwald"
#define APATH "/d/kristallwald/clementine/wassertroepfchen/"
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
#define TPUID capitalize(getuid(this_player()))
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())
#define WRITELOG(x) write_file(LOG("wassertroepfchen.log"),ctime()+":"+x+".\n")
#define QUESTLOG "/d/kristallwald/clementine/wassertroepfchen/log/"
#define QUESTITEM "\nwasserquest"
#define GOLDFISCH "\ngoldfisch"
#define QUESTKRAUT "\nQUESTKRAUT"
#define QUESTSAFT "\nQUESTSAFT"
#define QUESTNAME "Hustensaft fuer Wassertroepfchen"
#define ANSCHLUSS_KRISTALLWALD "/d/kristallwald/sargola/wald/room/1102"

#define CLOSURE(x) #'x
