/* removed use break_text :)
#include "/players/whisky/genesis/sys/break_string.h"
 */
#include "/players/whisky/genesis/sys/filter_live.h"
#define PATH "/players/whisky/island/room/"
#define SEA "/players/whisky/seaworld/room/"
#define MONST "/players/whisky/island/monster/"
#define OBJ "/players/whisky/island/obj/"
#define CM(x) move_object(clone_object(MONST+x),this_object())
#define CO(x) move_object(clone_object(OBJ+x),this_object())
#define BS(x) break_text(x+"\n",65)
