#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("West Dovin Road.");
    set_long(
      "Dovin Road is lightly traveled.  A dirty pub sprawls near the road to the north.  "
      "Wide areas on either side of it are devoid of houses.  "
      "The ancient stones underfoot running east and west make the road easy "
      "to follow. "
);
    set_night_long(
      "Running east and west through the northwest section of Tirun, "
      "this section of Dovin Road is often filled with noise "
      "from the pub that sits near the city wall.  The stones underfoot are "
      "hard to make out in the darkness. "
);
    set_smell("default", "It smells of stale beer.");
    set_exits( 
              (["east" : ROOMS"wdovin2",
                "west" : ROOMS"wdovin4",
                "enter pub" : ROOMS"brig_pub",
]) );
  add_exit_alias("enter pub", "pub");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
