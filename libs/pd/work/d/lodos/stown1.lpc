#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_properties(([ "town" : 1 ]));
   set_short("En route south of lodos");
   set_day_long("To the north the small town square can be seen, along "
     "with many different adventurers walking about the town. This road "
     "leads directly south and curves east further along its length. "
     "A smaller sized building lies west, with a sign outside of it.");
   set_night_long("To the north the small, and empty, town square can be "
     "seen, only a few tired citizens walk through it every now and then. "
     "This darkened road leads south a bit, but past that you cannot see. "
     "Some sort of shop with a sign hanging above it is west.");
   set_items(([
     "road" : "It is a very old road, leading into the oldest section of "
              "the small town of Lodos.",
     "building" : "An old building with a wooden sign above it, swinging "
                  "in the breeze.",
     "sign" : "It has a picture of a sword, knife and mace.",
     "square" : "That is the old Lodos square."
   ]));
   set_exits(([ "west" : ROOMS"weaponry",
                "south" : ROOMS"stown2",
                "north" : ROOMS"square" ]));
}

void reset() {
 ::reset();
   if (!present("citizen"))
     make(MOB"citizen");
   if (!present("citizen 2"))
     make(MOB"citizen");
}
