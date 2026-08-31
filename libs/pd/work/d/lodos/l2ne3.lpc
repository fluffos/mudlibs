#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("On top of the northeastern turret");
   set_day_long("This is the top of the northeastern turret. This room "
     "gives a good view over the rest of the temple. All three of the other "
     "turrets, the temple roof and a large tower in the center of the "
     "temple's roof. One turret is west, another south, and the last is "
     "southwest of this spot.");
   set_night_long("Three shadowy turrets and a tower can be seen in the "
     "night light from here. One turret is south, the second west, and the "
     "last turret is southwest of this spot. The tower is in the center of "
     "the temple's roof, which can also be seen across.");
   set_items(([
     "turrets" : "Three other turrets are visible from this spot.",
     "tower"   : "The tower is in the very center of the temple's roof."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1ne3",
     "north"     : ROOMS"l2ne1",
     "east"      : ROOMS"l2ne4",
   ]));
}

void reset() {
 ::reset();
   if (!present("guardian"))
     make(MOB"2t3");
}
