#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("The most southeastern point of the temple grounds");
   set_day_long("Of the entire area the temple takes up, this room is "
     "the furthest southeastern point of the entire temple. This corner "
     "of the room is not too well lit, but well enough to see that this "
     "room has no decoration at all. This is the southeastern turret.");
   set_night_long("This small, darkened room is the furthest southeastern "
     "point of the temple. It is dark, but not enough to completely blind "
     "you. White walls and tiled floor are the only decor of this bleak "
     "turret. Though it does not hold the same splendor of the rest of the "
     "temple, the turret has a sort of silent majesty.");
   set_items(([
     "point" : "This point is the furthest southeastern point of the "
               "temple.",
     "foo"   : "You'll never guess.."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2se4",
     "north" : ROOMS"l1se2",
     "west"  : ROOMS"l1se3"
   ]));
}

void reset() {
 ::reset();
   if (!present("apprentice"))
     make(MOB"t4");
}
