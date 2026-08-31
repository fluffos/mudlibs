#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Nearing the top of the tower");
   set_long("This part of the tower is just near the top. Stairs lead up into "
	"the room below the tower's ruler's chamber. Stairs lead west, along "
	"the lean of the tower.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"chamber" : "Near here are the chambers of the tower's ruler."
   ]));
   set_exits(([ "west" : ROOMS"ltower6",
		"up" : ROOMS"ltower8"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard");
     make(MOB"guard2");
     make(MOB"guard3");
     make(MOB"guard4");
   }
}
