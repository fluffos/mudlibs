#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_properties((["light" : 2]));
   set_long("The stairway has begun to thin out, because the tower was "
      "built on a bad foundation and can only support so much weight. "
      "The tower seems to almost lean to the east here. The staircase "
      "continues west and south.");
   set_exits(([ "west" : ROOMS"etower8",
                "south" : ROOMS"etower10"]));
   set_items(([
      "stairway" : "Because of the faulty foundation, the stairway has become narrow.",
      "tower" : "It almost seems to lean to one side.",
      "staircase" : "It continues south, up, and west, down."
   ]));
}

void reset() {
 ::reset();
   if (!present("knight"))
     make(MOB"knight");
   if (!present("soldier")) {
     make(MOB"soldier");
     make(MOB"soldier2");
   }
}
