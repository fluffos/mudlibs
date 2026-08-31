#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Top of the northwestern turret, just over the temple");
   set_day_long("From here, the whole roof of the temple is visible. It "
     "is a fairly level surface with a single tower in the center of it. "
     "The three other turrets are also viewable from here, one east, "
     "south, and the last southeast of this point.");
   set_night_long("The differing lights of the night give good lighting to "
     "the top of the turret, allowing sight across the top of the temple. "
     "A single tower sticks out of the center of the temple's otherwise "
     "level roof. All three other turrets are visible from here, east, "
     "south, and the last southeast of this point.");
   set_items(([
     "turrets" : "They are all visible from here.",
     "tower"   : "It sticks out of the center of the temple's roof."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1nw4",
     "north"     : ROOMS"l2nw2",
     "west"      : ROOMS"l2nw3"
   ]));
}

void reset() {
 ::reset();
   if (!present("avatar"))
     make(MOB"2t4");
}
