#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Northwestern turret of the temple");
   set_day_long("The northeastern corner of the northwestern turret of "
     "the temple is a small room. Tiled floor leads west and south to "
     "some of the other corners of this perticular turret. Travel is also "
     "possible upwards to the higher portion of the turret.");
   set_night_long("Tiled floor passages lead south and west to other "
     "corners of this turret. This is the northwestern turret of the "
     "temple. The turret also goes further up, though vision at night over "
     "the surrounding land may not be the best.");
   set_items(([
     "turret" : "You are currently in the northwestern turret of the "
                "temple.",
     "corner" : "One of the bottom corners of the turret.",
     "floor"  : "It happens to be tiled, big surprize. :P"
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2nw2",
     "west"  : ROOMS"l1nw1",
     "south" : ROOMS"l1nw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("sage"))
     make(MOB"t2");
}
