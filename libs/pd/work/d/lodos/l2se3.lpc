#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Top of the southeastern turret");
   set_day_long("This is one corner of the top of the southeastern turret. "
     "From atop this turret, a second turret, the southwestern turret, "
     "along with the tower in the middle of the temple. This turret "
     "reaches just above the height of the main temple.");
   set_night_long("Moonlight shines onto the southeastern turret, "
     "illuminating the view from here. This is a platform on top of the "
     "roof of the southeastern turret. Through the night light, the "
     "southwestern turret can be viewed from this point.");
   set_items(([
     "turret" : "You can see the southwestern turret from here."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1se3",
     "north"     : ROOMS"l2se1",
     "east"      : ROOMS"l2se4",
   ]));
}

void reset() {
 ::reset();
   if (!present("guardian"))
     make(MOB"2t3");
}
