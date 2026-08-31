#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Inside of the Leaning Tower of Lodos");
   set_long("The tower leans and tilts to the east. Stairs wrap around the "
	"tower, leading slightly upwards and east at the same time. The Leaning "
	"Tower of Lodos goes east and down from here.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"stairs" : "They go down and east from here.",
   ]));
   set_exits(([ "down" : ROOMS"ltower4",
		"east" : ROOMS"ltower6"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard2");
     make(MOB"guard3");
     make(MOB"guard3");
   }
}
