#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Inside of the Leaning Tower of Lodos");
   set_long("While wandering through this tower, one can't help but imagine just "
	"how stupid the person that constructed this tower must feel. Just what "
	"sort of punishment would be used against the builder of a faulty tower? "
	"One can but only imagine.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
   ]));
   set_exits(([ "west" : ROOMS"ltower2",
		"east" : ROOMS"ltower4"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard2");
     make(MOB"guard");
   }
}
