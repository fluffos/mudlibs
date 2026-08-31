/* moved out take please the efun break_text
#include "/players/whisky/genesis/sys/break_string.h"
 */
#include "/players/whisky/genesis/sys/filter_live.h"
#define BS(x) break_text(x+"\n",60);
#define MONST "/players/whisky/meadow/monster/"
#define PATH "/players/whisky/meadow/room/"
#define OBJ "/players/whisky/meadow/obj/"
#define SEA "/players/whisky/seaworld/room/"
#define CO(x) move_object(clone_object(OBJ+x),this_object())
#define CM(x) move_object(clone_object(MONST+x),this_object())
#define WOOD "/players/whisky/garden/room/"
