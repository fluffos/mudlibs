/* removed use the efun break_text please
#include "/players/whisky/genesis/sys/break_string.h"
*/
#include "/players/whisky/genesis/sys/filter_live.h"
#define PATH "/players/whisky/hole/room/"
#define MONST "/players/whisky/hole/monster/"
#define OBJ "/players/whisky/hole/obj/"
#define CM(x) move_object(clone_object(MONST+x),this_object())
#define CO(x) move_object(clone_object(OBJ+x),this_object())
#define BS(x) break_text(x+"\n",60)
