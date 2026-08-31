#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("North Veros Road.");
    set_long(
      "Running north and south through the center of Tirun, Veros Road "
      "stays busy.  Some distance south the road opens into a broad open square. "
      " To the north the tops of trees can be seen above the city walls. "
      " The ancient stones underfoot running north and south make the "
      "road easy to follow. "
);
    set_night_long(
      "Running north and south through the center of Tirun, Veros Road "
      "is peaceful at night.  The road leads away into the darkness to "
      "the north and south.  The stones underfoot are hard to make out "
      "in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"nveros6",
                "south" : ROOMS"nveros4",
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
