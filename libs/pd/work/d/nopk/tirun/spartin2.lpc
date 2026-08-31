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
      "There is something burning to the south.");
    set_night_long(
      "Running east and west between Ganthus Circle and Parthos Road, "
      "Spartin Way is peaceful at night.  Shadows to the north and south "
      "show themselves to be buildings.  The stones underfoot are hard to "
      "make out in the darkness. "
      "There is something burning to the south.");
    set_exits( 
              (["west" : ROOMS"spartin1",
                "east" : ROOMS"nparthos3",
       "enter pyromancer hall" : ROOMS"mage/pyromancer/pyromancer_join",
]) );
add_exit_alias("enter pyromancer hall", "hall");
add_exit_alias("enter pyromancer hall", "pyromancer");
add_exit_alias("enter pyromancer hall", "pyromancer hall");
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

