#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Passage between northeastern turret and temple");
   set_day_long("There is a passageway connecting this turret to the main "
     "temple southwest. Daylight streams in from a man-sized hole in the "
     "ceiling. A ladder leads up to the hole, allowing movement upwards. "
     "The turret has white walls and floors, much like the rest of the "
     "temple.");
   set_night_long("A passage between this northeastern turret and the rest "
     "of the temple is here. A southwestern passageway connects into this "
     "room. A small ammount of star and moon light enters through a hole "
     "in the ceiling, leading up to higher platform of the turret. The "
     "walls and floor look very much like the rest of the temple.");
   set_items(([
     "walls" : "White onyx with grey streaks through it.",
     "floor" : "Tiled white stone floor.",
     "light" : "The available light enters from the hole in the ceiling",
     "hole"  : "A man-sized hole in the ceiling leads up."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"        : ROOMS"l2ne3",
     "north"     : ROOMS"l1ne1",
     "southwest" : ROOMS"l1m3",
     "east"      : ROOMS"l1ne4",
   ]));
}

void reset() {
 ::reset();
   if (!present("master"))
     make(MOB"t3");
}
