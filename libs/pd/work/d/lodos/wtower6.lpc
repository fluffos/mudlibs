#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing up a tower along the stairs");
   set_properties((["light" : 3, "indoors" : 1 ]));
   set_long("The light here is brighter, although for no apparent reason, "
      "because there are no windows here. The air is warm and humid here. "
      "The stairs continue up and down into the tower.");
   set_exits(([ "up" : ROOMS"wtower7",
                "down" : ROOMS"wtower5"]));
   set_items(([
      "air" : "It is thick and almost hard to breathe.",
      "light" : "A strange glow fills the room.",
      "stairs" : "They lead up, almost like a ladder."
   ]));
}

void reset() {
 ::reset();
   if (!present("knight"))
     make(MOB"knight");
   if (!present("paladin"))
     make(MOB"paladin");
}
