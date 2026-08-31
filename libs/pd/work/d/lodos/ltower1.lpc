#include <lodos.h>
#include <std.h>
inherit VAULT;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 1,
     "indoors" : 1 ]));
   set_short("Bottom of a tower");
   set_long("This is the base of a leaning tower. The tower was built upon "
	"unstable ground, and because of it's faulty foundation, will continue "
	"to tilt more and more east until one day it will come crashing down. "
	"Stairs lead up the tower.");
   set_items(([
	"stairs" : "They are slanted towards the eastern horizon, like the tower.",
	"foundation" : "It was build on soft ground.",
	"tower" : "The Leaning Tower of Lodos."
   ]));
   set_exits(([ "out" : ROOMS"stown5",
	"up" : ROOMS"ltower2"
   ]));
   set_door("door", ROOMS"stown5", "out", "");
}

void reset() {
 ::reset();
   if (!present("guard"))
     make(MOB"guard");
}
