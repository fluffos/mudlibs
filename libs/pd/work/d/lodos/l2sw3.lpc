#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("The highest southwestern most point of the turret of heart");
   set_day_long("This is the highest southwestern most point of the turret "
     "of heart. The ground is a dark red stone and becomes black around "
     "the hole leading down into the bottom floor of the turret. A silver "
     "ladder has been propped up from below, and pokes just out of the top "
     "of the hole.");
   set_night_long("This is the highest southwestern most point of the "
     "turret of heart. The night makes the red stone floor look almost "
     "black. The stone around the hole is black. A silver ladder pokes out "
     "of the hole. This hole leads back down to the bottom floor of the "
     "turret.");
   set_items(([
     "ladder" : "A thin, silver ladder.",
     "hole"   : "The hole backdown to the bottom of the turret.",
     "ground" : "Dark red stone."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1sw3",
     "north"     : ROOMS"l2sw1",
     "east"      : ROOMS"l2sw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("guardian"))
     make(MOB"2t3");
}
