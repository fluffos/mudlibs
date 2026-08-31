#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("Spartin Way.");
    set_long(
      "Running east and west between Ganthus Circle and Parthos Road, "
      "Spartin Way is lightly traveled.  A large white marble building "
      "is to the south.  Houses line the road to the north.  The ancient "
      "stones underfoot running north and south make the road easy to follow. "
);
    set_night_long(
      "Running east and west between Ganthus Circle and Parthos Road, "
      "Spartin Way is peaceful at night.  Shadows to the north and south "
      "show themselves to be buildings.  The stones underfoot are hard to "
      "make out in the darkness. "
);
    set_exits( 
              (["west" : ROOMS"eganthus3",
                "east" : ROOMS"spartin2",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "marketplace" : "The center of commerce in Tirun.",
          "ships" : "Big boats berthed at the Tirun Docks.",
          "mast" : "A large pole on which a sail is hung."
         ]) );
}
