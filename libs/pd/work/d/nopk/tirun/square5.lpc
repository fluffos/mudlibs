#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("%^BOLD%^Tirun Market Square.%^RESET%^");
//DO NOT CHANGE THIS DESCRIPTION!!!!
    set_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  Buildings to the east and west "
      "stand along the side of the road with their doors open and ready for business. "
      " Ancient stone tiles underfoot run south, west, and east making "
      "the road easy to follow.  A fence to the north marks the boundaries "
      "of a park and an opening in the fence provides access there in. "
      " Veros road leads the way south toward the city walls of Tirun. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  Shadows along "
      "side of the road to the east and west coalesce into buildings.  "
      "The stones underfoot are hard to make out and things look different "
      "in the darkness.  The road seems to travel south, west, and east.  "
      "An opening in the fence to the north leads into a well lit area. "
      );
    set_exits( ([
       "north" : ROOMS "square",
       "south" : ROOMS "sveros1",
       "west" : ROOMS "square6",
       "east" : ROOMS "square4" 
    ]) );

    set_items( ([
        "road" : "Ancient stone tiles pave the road.",
        "shop" : "A place to buy and trade goods.",
        "shops" : "Places to buy and trade goods.",
        "fence" : "A wooden structure.",
        "building" : "A structure made of stone.",
        "square" : "The Market Square of Tirun."
      ]) );
}
