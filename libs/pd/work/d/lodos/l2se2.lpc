#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Above the southeastern turret");
   set_day_long("This is part of the platform roof above the southeastern "
     "turret. From the this platform, the northeastern turret is visible. "
     "Although they are not much higher than the rest of the main temple, "
     "the turrets are the highest point of the temple besides the tower "
     "in the center of the temple.");
   set_night_long("The platform roof above the southeastern turret is one "
     "of the highest places on the surrounding hill, though it is not much "
     "higher than the rest of the temple. From this point, the northeast"
     "ern turret can be seen. The eastern side of the temple is also "
     "completely visible in the night.");
   set_items(([
     "temple" : "Most of the temple is visible from here.",
     "turret" : "The northeastern turret can be seen."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1se2",
     "west"  : ROOMS"l2se1",
     "south" : ROOMS"l2se4",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t2");
}

