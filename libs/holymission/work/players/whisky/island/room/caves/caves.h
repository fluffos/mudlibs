
/* caves.h */

/* no longer needed
#include "/players/whisky/genesis/sys/break_string.h"
   use the efun break_text :) */
#include "/players/whisky/genesis/sys/filter_live.h"
#define PATH "/players/whisky/island/room/caves/room/"
#define MON "/players/whisky/island/room/caves/monster/"
#define OBJ "/players/whisky/island/room/caves/obj/"

#define CM(x) move_object(clone_object(MON+x),this_object())
#define CO(x) move_object(clone_object(OBJ+x),this_object())
#define BS(x) break_text(x+"\n",65) 
