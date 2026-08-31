inherit "/players/whisky/seaworld/water";
/* moved out there is an efun break_text now ! :)
#include "/players/whisky/genesis/sys/break_string.h"
  */
#include "/players/whisky/genesis/sys/filter_live.h"
#define PATH "/players/whisky/lake/room/"
#define MONST "/players/whisky/lake/monster/"
#define OBJ "/players/whisky/lake/obj/"
#define CM(x) move_object(clone_object(MONST+x),this_object())
#define CO(x) move_object(clone_object(OBJ+x),this_object())
#define BS(x) break_text(x+"\n",60) 
