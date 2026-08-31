#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing up a tower along the stairs");
   set_properties((["light" : 2, "indoors" : 1 ]));
   set_long("The stairs climb higher and higher, up into the tower. "
      "Small windows line the sides of the wall, letting in air and "
      "light from outside. The air in here is chilling and cold.. That's "
      "strange for this usually warm tower.");
   set_exits(([ "up" : ROOMS"wtower6",
                "east" : ROOMS"secret3",
                "down" : ROOMS"wtower4"]));
   set_items(([
      "stairs" : "The stairs climb up the side of the tower.",
      "air" : "It is strangely cold..",
      "cold" : "The cold air seems to be comming from the eastern wall.",
      "wall" : "The eastern wall is letting the air in.."
   ]));
   set_invis_exits(({ "east" }));
}

void reset() {
 ::reset();
   if (!present("knight")) {
     make(MOB"knight");
     make(MOB"knight");
   }
   if (!present("squire"))
     make(MOB"squire");
}
