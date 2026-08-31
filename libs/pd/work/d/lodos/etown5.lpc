#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("On a path leading east");
   set_property("light", 2);
   set_properties(([ "town" : 1 ])); 
   set_long("The road leads east and west. To the west along the path "
      "is a small privately-owned cafe. A shack lies just to the east. "
      "A thin trail of smoke leads up from the shack.");
   set_items(([
      "shack" : "The shack is southeast of here.",
      "smoke" : "A fire must be lit in the shack.",
      ({ "path", "road" }) : "A thin dirt road.",
      "cafe" : "The Golden Talon Cafe lies just to the west.",
   ]));
   set_exits(([ "west" : ROOMS"etown4",
                "east" : ROOMS"etown6" ]));
}

void reset() {
 ::reset();
   if (!present("citizen")) {
      make(MOB"citizen");
      make(MOB"citizen");
   }
}
