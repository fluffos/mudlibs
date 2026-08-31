// - Inferno -  The bread and board inn =) =) =)
#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside the walls of the bread and board inn");
   set_day_long("This is the front room of a "
     "small, two story inn. A winding staircase leads up to the second "
     "story.  A small door leads to the west.  The floor is of beautifully "
     "polished wood. A small reception desk stands "
     "at the far side of the room.");
   set_night_long("This is the foremost room of a small, family owned, "
     "two story inn. A winding staircase, leading up to the second " 
     "story, is covered in the shadows of night.  A small door leads to "
     " west.  The beautifully polished wooden floor glistens in the moon "
     "light.");
   set_exits(([
      "out" : ROOMS"town5",
      "west" : ROOMS"west_inn",
      "stairs" : ROOMS"stairs",
   ]));
   set_items(([
      "floor" : "It adds a great touch to the inn",
      "staircase" : "The staircase leads up to the second story."
   ]));
}

void reset() {
 ::reset();
   if (!present("desk"))
      make(OBJ"desk");
}
