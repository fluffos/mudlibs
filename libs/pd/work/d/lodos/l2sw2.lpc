#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Just southwest of the temple on top of a turret");
   set_day_long("The stone that makes up the ground is dark red. A single "
     "hole in the ground is the way back down to the ground floor of the "
     "turret. The stone around the hole and below it is white. Lava rocks "
     "have been stacked around the turret to form a small ledge.");
   set_night_long("The red stone ground relects the dark night sky, making "
     "the stone look even darker. There is a single hole near the middle "
     "of the room, leading back down into the turet of heart. The stone "
     "around the hole is white, as well as the stone below the hole.");
   set_items(([
     "hole"  : "A hole down into the turret of heart.",
     "temple": "It can be seen very clearly from here.",
     "stone" : "It varies from red to white."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1sw2",
     "west"  : ROOMS"l2sw1",
     "south" : ROOMS"l2sw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t2");
}

