#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Along a twisted staircase");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The twisted spiral staircase leads south and west, "
      "west down it and south further up into it. A trail of water "
      "leads west. Out the window you can see the dirt path.");
   set_exits(([ "west" : ROOMS"etower3",
                "south" : ROOMS"etower5"]));
   set_items(([
      "staircase" : "It leads up the tower in a twisted spiral.",
      ({ "trail", "water" }):"A trail of water leads through the room, heading west.",
      "window" : "Through the window, the path outside can be seen.",
      "path" : "It can be seen through the window."
   ]));
}

void reset() {
 ::reset();
//   if (!present("knight"))
//     make(MOB"knight");
}
