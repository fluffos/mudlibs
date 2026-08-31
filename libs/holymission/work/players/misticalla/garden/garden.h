/* moved out take please break_text :)
#include "/players/whisky/genesis/sys/break_string.h"
 */
#include "/players/whisky/genesis/sys/filter_live.h"
#define	WIZ	"players/whisky"
#define	ROOM	WIZ+"/garden/room"
#define PATH    WIZ+"/garden/room/"
#define MONST   WIZ+"/garden/monster/"
#define OBJ     WIZ+"/garden/obj/"
#define MEAD    WIZ+"/meadow/room/" 
#define TO   this_object()
#define E   environment
#define RP    replace_program("room/room") 
#define CM(x) move_object(clone_object(MONST+x),TO) 
#define CO(x) move_object(clone_object(OBJ+x),TO)
#define BS(x) break_text(x+"\n",60) 
