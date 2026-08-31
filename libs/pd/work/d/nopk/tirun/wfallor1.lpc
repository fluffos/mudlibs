#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("West Fallor Road.");
    set_long(
      "Fallor Road is lightly traveled.  Houses line the road to the "
      "north.  The ancient stones underfoot running east and "
      "west make the road easy to follow. To the south is a "
       "medium-sized building with a large sign declaring it to be "
       "the Tirun Auction House."
);
    set_night_long(
      "Running east and west through the southwest section of Tirun, "
      "Fallor Road is peaceful at night.  Shadows to the north and south "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. The building to the south has a large sign on it."
);
    set_exits( 
              (["west" : ROOMS"wfallor2",
                "east" : ROOMS"sveros4",
                 "enter auction house" : ROOMS"auc_house"
 ]) );
add_exit_alias("enter auction house", "auction house");
add_exit_alias("enter auction house", "auction");
add_exit_alias("enter auction house", "house");
add_exit_alias("enter auction house", "south");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
           "sign" : "Tirun Auction House",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
