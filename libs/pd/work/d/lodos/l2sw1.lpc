#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Atop the turret of heart");
   set_day_long("The ground above the turret of heart is a dark red stone. "
     "Within the red stone every few feet or so is a black streak. A hole "
     "has been carved into the red stone leading down. Around the hole, "
     "the stone is black. Lava rocks have been stacked around the edge of "
     "the turret to form a small ledge.");
   set_night_long("Through the night light the dark red stone ground can "
     "be seen. The stone around the hole in the ground is black. The hole "
     "is the way back down to the ground floor of the turret of heart. "
     "Along the outer edge of the turret, lava rocks have been piled up to "
     "form a small ledge.");
   set_items(([
     "ledge" : "The ledge is made of lava rocks.",
     "rocks" : "Light weight black rocks with many holes in them.",
     "hole"  : "The stone around the hole is black.",
     "ground": "Red and black stone."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1sw1",
     "east"  : ROOMS"l2sw2",
     "south" : ROOMS"l2sw3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t1");
}

