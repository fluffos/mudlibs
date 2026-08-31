#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("The turret of heart");
   set_day_long("The tiled floor of this part of the turret of heart is "
     "dark blue as it nears the western doorway and fades to white as it "
     "nears the northern wall. Right here, the floor is blue. The walls "
     "are a red and blue stone of some sort. Again, the wall gets lighter "
     "north and darker west.");
   set_night_long("The red and blue walls get lighter as they near the "
     "northern exit and darker as they get closer to the western exit. "
     "The same hue variation is in the tiled blue floor as well. A hole "
     "in the ceiling lets light into this part of the turret of heart.");
   set_items(([
     "walls" : "Lighter north and darker west. They are red and blue.",
     "floor" : "Lighter north and darker west. The tiled floor is blue."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2sw4",
     "north" : ROOMS"l1sw2",
     "west"  : ROOMS"l1sw3"
   ]));
}

void reset() {
 ::reset();
   if (!present("apprentice"))
     make(MOB"t4");
}
