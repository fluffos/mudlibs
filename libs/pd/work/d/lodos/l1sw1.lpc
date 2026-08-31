#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Turret of heart");
   set_day_long("The southeastern turret is known as the turret of heart. "
     "The walls are a dark, almost blood red and midnight blue. The tiled "
     "floor is blue, but fades to white as it nears the eastern doorway. "
     "going south, the blue tile gets darker. The red and blue on the walls "
     "also varies in hue as the tile does.");
   set_night_long("The walls are red and blue, and in the night it looks "
     "like a midnight blue and magenta. The tiled ground is blue, though "
     "it fades to white as it nears the eastern doorway and black as it "
     "approaches the southern doorway. The blue relects off the ground onto "
     "the wall, making the magenta look even crimson in some parts. This "
     "turret is known as the turret of heart.");
   set_items(([
     "turret" : "The turret of heart, though you know not how it got it's "
                "name.",
     "tile"   : "White at the eastern doorway, dark blue near the southern, "
                "and blue here.",
     "walls"  : "Crimson and midnight blue.",
     "turret" : "You are within the turret of heart."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2sw1",
     "east"  : ROOMS"l1sw2",
     "south" : ROOMS"l1sw3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"t1");
}
