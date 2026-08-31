#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Above the southeastern turret and the temple");
   set_day_long("This platform is on top of one of the corners of the "
     "southeastern turret and the southeastern most corner of the main "
     "temple. Just below the turret a passageway can be seen connecting "
     "the turret and temple. A tower is in the center of the temple, the "
     "tallest place on the temple.");
   set_night_long("Through the darkness of night, a tower can be seen in "
     "the center of the temple. Below this platform, which is above the "
     "southeastern turret, a passageway can be seen that connects the "
     "temple to the turret. Looking west, the southwestern turret can "
     "be seen.");
   set_items(([
     "turret"    : "The southwestern turret can be seen west.",
     "tower"     : "A single tower, like a spire, in the center of the "
                   "temple.",
     "passageway": "It connects the southeastern turret to the temple."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1se1",
     "east"  : ROOMS"l2se2",
     "south" : ROOMS"l2se3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t1");
}

