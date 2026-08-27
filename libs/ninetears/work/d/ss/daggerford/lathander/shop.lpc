#include "path.h"

inherit "/std/shop";

void setup()
{
set_short("Temple of Lathander: Shop");
set_long("Temple of Lathander: Shop\n\n"+
   "This is a small room with several shelves from which to \"buy\" "+
   "equipment.  If you want to, you can simple \"browse\" around.  "+
   "A \"list\" of equipment may also be obtained.  "+
   "Sorry, but you can not sell in this shop.\n\n");
add_item("shelves", "These small shelve house several small trinkets usable "+
   "by the clerics of Lathander.\n");
        set_light(60);
	add_exit("west", ROOM+"lath14", "door");
	set_store_room(ROOM+"store_room");
}
