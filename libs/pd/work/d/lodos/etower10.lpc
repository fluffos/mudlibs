#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a thinning staircase");
   set_properties((["light" : 2, "town" : 1, "indoors" : 1,
     "building" : 1]));
   set_long("The thinning staircase leads west up into a smaller room. "
      "To the north, the stairs are a bit wider, though not by very "
      "much. The spiral staircase is almost ended. You see that the "
      "stairs are cut off to the west.");
   set_exits(([ "north" : ROOMS"etower9",
                "west" : ROOMS"etower11"]));
   set_items(([
      "west" : "The room to the west is smaller, but higher in the tower.",
      "staircase" : "It leads north and west.",
      "stairs" : "They get wider to the north",
   ]));
}

void reset() {
 ::reset();
   if (!present("knight")) {
     make(MOB"knight");
     make(MOB"knight");
     make(MOB"knight");
   }
}
