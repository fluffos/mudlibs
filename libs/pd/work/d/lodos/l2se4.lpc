#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("The far southeast of the turret"); 
   set_day_long("This is the far southeastern corner of the southeast "
     "corner. The whole southeastern hillside can be seen from this "
     "part of the turret. There is a hole in the ground with a metal "
     "ladder sticking about two feet out of it. This hole leads down to "
     "the bottom of the southeastern turret.");
   set_night_long("This is the farthest southeastern corner of the turret "
     "and temple. The entire star lit southeastern hillside can be seen "
     "from this part of the turret. There is a hole near the edge of the "
     "turret with a metal ladder sticking about two feet out of it. This "
     "hole leads down to the bottom of this turret.");
   set_items(([
     "hole"   : "The way back down the turret.",
     "ladder" : "A metal ladder that leads down to the ground floor.",
     "edge"   : "The edge of the turret, the hole is right near this."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1se4",
     "north"     : ROOMS"l2se2",
     "west"      : ROOMS"l2se3"
   ]));
}

void reset() {
 ::reset();
   if (!present("avatar"))
     make(MOB"2t4");
}
