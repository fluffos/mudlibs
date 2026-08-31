// - Inferno -  The bread and board inn =) =) =)
// NOTE: add search for a book

#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
 ::create();
   set_short("inside Lodos Inn");
   set_long("You reach a small hallway going from east to west.  A door to the north "
     "marks one of the rooms for rent.  The carpet is fresh and squishy, making this "
     "inn seem almost like new.");
   set_exits(([
      "stairs" : ROOMS"inn",
      "east" : ROOMS"east_stairs",
      "west" : ROOMS"west_stairs"
   ]));
}
