#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Inside of the Leaning Tower of Lodos");
   set_long("The tower leans and the stairs seldomly make an upwards turn, going "
	"higher rather than lower. The stairs make one of those turns at this "
	"very point in the tower, heading up the leaning mass. The ground below "
	"can be seen through a window that was meant to look into the forest.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"stairs" : "They go up and west from here.",
	"window" : "Because of the tower's lean, it now looks down instead of "
			"east.",
   ]));
   set_exits(([ "west" : ROOMS"ltower3",
		"up" : ROOMS"ltower5"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard")) {
     make(MOB"guard2");
     make(MOB"guard2");
     make(MOB"guard");
   }
}
