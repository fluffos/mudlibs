// - Inferno -  Entrance to 'Asgard', the resting place
// of the coffin of a powerful magician, which adds a strange
// magical property to everything in the no longer peaceful town

#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("standing before silver gates");
   set_long("The short road ends here, directly before the "
            "town. Large silver gates stand before you, and "
            "two guards stand ready at their posts, ready to "
            "defend the city against danger. A new road leads "
            "east through the gates, into the town.");
   set_exits(([
      "west" : "/d/standard/frealmz/mist2",
      "east" : "/d/standard/frealmz/town1"
   ]));
   set_items(([
      "gates" : "The large silver gates stand before you.",
      "road" : "It ends before the town gates.",
      "town" : "It has a strange look to it, but you can't place "
               "a finger on exactly what."
   ]));
}

void reset() {
 ::reset();
   if (!present("gate guard")) {
      new("/d/standard/frealmz/mob/gate_guard")->move(this_object());
      new("/d/standard/frealmz/mob/gate_guard")->move(this_object());
   }
}
