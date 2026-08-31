#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("North Veros Road.");
    set_long(
      "Running north and south through the center of Tirun, Veros Road "
      "stays busy.  Wayward Avenue intersects Veros Road running east and "
      "west from here.  To the north the city gate opens onto the northern forest. "
      "The ancient stones underfoot run north, south, west, and east "
      "making the road easy to traverse. "
);
    set_night_long(
      "Running north and south through the center of Tirun, Veros Road "
      "is peaceful at night.  A dark road intersects Veros here leading "
      "west and east into the darkness.  Veros continues north and south. "
      " The ancient stones underfoot are hard to make out in the dark. "
);
    set_exits( 
              (["north" : ROOMS"nveros5",
                "south" : ROOMS"nveros3",
                "east"  : ROOMS "ewayward1",
                "west"  : ROOMS "wwayward1",
]) );

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into square and layed to make a road.",
          "marketplace" : "The center of commerce in Tirun.",
          "ships" : "Big boats berthed at the Tirun Docks.",
          "mast" : "A large pole on which a sail is hung."
         ]) );
}
