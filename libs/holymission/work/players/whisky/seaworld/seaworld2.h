#include "/players/whisky/genesis/sys/break_string.h"
#include "/players/whisky/genesis/sys/filter_live.h"
#define WIZ "players/whisky/"
#define PATH WIZ+"seaworld/room/"
#define OBJ WIZ+"seaworld/obj/"
#define MONST  WIZ+"seaworld/monster/"
#define BS(x)  break_string(x+"\n",60 ) 
#define CM(x)   move_object(clone_object(MONST+x),this_object())
#define CO(x)   move_object(clone_object(OBJ+x),this_object())
#define RP  replace_program("room/room")
