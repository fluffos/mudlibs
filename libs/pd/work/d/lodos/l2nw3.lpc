#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Atop the northwestern turret");
   set_day_long("This is the top of the northwestern turret. Because there "
     "is no ceiling to the turret, below this turret may not be the best "
     "place to be during a storm. A small hole in the ground leads back "
     "down to the bottom floor of the turret. Looking south, one could see "
     "another turret, the southwestern turret.");
   set_night_long("Moonlight and starlight light up the top of the "
     "northwestern turret. Looking south, the southwestern turret can be "
     "spotted. A very small hole is the way back down to the ground floor "
     "of this turret. The stone ledge gives a place to sit and relax when "
     "not under seige.");
   set_items(([
     "hole"  : "How the bloody hell does someone squeeze through that??",
     "ledge" : "A raised ledge around the edge of the turret.",
     "turret": "Another turret. The southwestern turret of the temple."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1nw3",
     "north"     : ROOMS"l2nw1",
     "east"      : ROOMS"l2nw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("guardian"))
     make(MOB"2t3");
}
