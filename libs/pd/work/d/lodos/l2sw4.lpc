#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("One corner on top of the turret of heart"); 
   set_day_long("This corner atop the red stone turret of heart has an "
     "excellent view of the area in front of the temple. From here the "
     "front entrance as well as a path leading onto the hill up to the "
     "doors can be seen. The tower in the center of the temple and all "
     "three other turrets are visible from here.");
   set_night_long("Beneath the night sky, all three turrets, the tower "
     "and the area in front of the temple can be seen. A road winds up "
     "the hill and up to the front of the temple. From here, the whole "
     "front of the temple can be seen and protected.");
   set_items(([
     "hill"  : "A small hill that the temple rests atop.",
     "road"  : "The road leads up the hill to the front doors of the "
               "temple.",
     "front" : "From here, the front of the temple can be monitored.",
     "temple": "It can be protected from here."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1sw4",
     "north"     : ROOMS"l2sw2",
     "west"      : ROOMS"l2sw3"
   ]));
}

void reset() {
 ::reset();
   if (!present("avatar"))
     make(MOB"2t4");
}
