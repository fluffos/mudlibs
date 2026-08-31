#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Inside of the Leaning Tower of Lodos");
   set_long("The leaning tower has come to yet another eastern slope. The slope "
	"goes east then back up the stairs again. The Leaning Tower of Lodos "
	"is a wreck!");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"stairs" : "They go east and west from here.",
   ]));
   set_exits(([ "west" : ROOMS"ltower5",
		"east" : ROOMS"ltower7"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard");
     make(MOB"guard4");
     make(MOB"guard4");
   }
}
