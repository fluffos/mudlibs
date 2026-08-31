#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("South Xelan Road.");
    set_long(
      "South Xelan Road is lightly traveled.  Houses line the road to the "
      "east and west.  The ancient stones underfoot running north and "
      "south make the road easy to follow. "
);
    set_night_long(
      "South Xelan is peaceful at night.  Shadows to the east and west "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"sxelan2",
                "south" : ROOMS"sxelan4",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
