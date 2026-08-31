#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Inside of the Leaning Tower of Lodos");
   set_long("Stairs lead down to the base of this tower. Also, the stairs go "
	"upwards along towards the eastern horizon, because of the tower's "
	"slanting position.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"stairs" : "They lead up and east.",
   ]));
   set_exits(([ "down" : ROOMS"ltower1",
		"east" : ROOMS"ltower3"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard");
     make(MOB"guard");
   }
}
