#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("The top of the tower");
   set_long("This is the very top of the leaning tower. The only obvious exit "
	"from this room is west, back down the tower. This is the lord of the "
	"tower's chamber. He guards his privacy jealously.");
   set_items(([
	"tower" : "The Leaning Tower of Lodos.",
	"chamber" : "The chambers of the tower's ruler."
   ]));
   set_exits(([ "west" : ROOMS"ltower8"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard"))
     make(MOB"guard5");
   if (!present("lord"))
     make(MOB"lord");
}
