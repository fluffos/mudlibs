#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("Xanth Road.");
    set_long(
      "Xanth Road is lightly traveled.  Houses line the road to the "
      "west.  The ancient stones underfoot running north, south, and "
      "west make the road easy to follow. "
);
    set_night_long(
      "Fallor Road is peaceful at night.  Shadows to the east "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"xanth3",
                "south" : ROOMS"xanth1",
                "west" : ROOMS"efallor3",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
