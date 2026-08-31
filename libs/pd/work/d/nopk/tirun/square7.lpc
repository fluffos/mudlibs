#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("%^BOLD%^Tirun Market Square.%^RESET%^\n");
//DO NOT CHANGE THE DESCRIPTION!!!!
    set_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  To the north and south buildings "
      "line the road with doors opened wide.  Ancient stone tiles underfoot run "
      "north and east making the road easy to follow.  A fence to the east marks "
      "the boundaries of a park and an opening in the fence provides access there "
      "in.  Honin road leads the way west toward the city walls of Tirun. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  Shadows along "
      "side of the road to the north and south coalesce into buildings.  "
      "The stones underfoot are hard to make out and things look different "
      "in the darkness.  The road seems to travel north, south, and west. "
      " An opening in the fence to the east leads into a well lit area. "
      );
    set_exits( ([
       "north" : ROOMS "square8",
       "south" : ROOMS "square6",
       "west" : ROOMS "whonin1",
       "east" : ROOMS "square" 
    ]) );

    set_items( ([
        "road" : "Ancient stone tiles pave the road.",
        "shop" : "A place to buy and trade goods.",
        "shops" : "Places to buy and trade goods.",
        "fence" : "A wooden structure.",
        "building" : "A structure made of stone.",
        "square" : "The Market Square of Tirun.",
        "sign" : "A shingle with a painting on it."
    ]) );
}
