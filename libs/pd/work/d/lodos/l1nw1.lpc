#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Northwestern most point of the entire temple");
   set_day_long("This is the very northwestern most point of the entire "
     "temple and of the northwestern turret as well. A ladder has been "
     "propped up into a hole in the ceiling leading upwards, higher into "
     "the turret. The turret is a guard post of sorts for the temple. This "
     "is as holy and blessed as armed defense gets!");
   set_night_long("Having only a small, thin window in this corner of the "
     "turret, it is very hard to see during the already dim night light. "
     "This night post is about as holy as armed defense will ever get! A "
     "ladder and a hole in the ceiling provide passage up, into the second "
     "story of the turret.");
   set_items(([
     "ladder" : "An old wooden ladder with exactly twelve steps.",
     "steps"  : "The very bottom ladder step has been removed, leaving "
                "twelve.",
     "turret" : "This is holy defense. Forget ADT, magic-flinging priests "
                "are REAL security.",
     "hole"   : "The hole in the ceiling leads up into the second story."
   ]));
   set_properties(([ "light" : 2, "night light" : 0, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2nw1",
     "east"  : ROOMS"l1nw2",
     "south" : ROOMS"l1nw3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"t1");
}
