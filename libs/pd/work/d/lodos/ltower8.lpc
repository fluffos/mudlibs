#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Just below the top of the tower");
   set_long("This room is just below the chambers of the leaning tower's lord. "
	"Stairs lead down further into the heart of the tower. East is the "
	"top point of the leaning tower.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"chamber" : "The chambers of the tower's ruler."
   ]));
   set_exits(([ "down" : ROOMS"ltower7",
		"east" : ROOMS"ltower9"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard5");
     make(MOB"guard5");
     make(MOB"guard5");
   }
}
