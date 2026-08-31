#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("West Fallor Road.");
    set_long(
      "Fallor Road is lightly traveled.  Houses line the road to the "
      "north and south.  The ancient stones underfoot running east and "
      "west make the road easy to follow. "
);
    set_night_long(
      "Running east and west through the southwest section of Tirun, "
      "Fallor Road is peaceful at night.  Shadows to the north and south "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. "
);
    set_exits( 
              (["west" : ROOMS"wfallor4",
                "east" : ROOMS"wfallor2",
        "enter weaponsmith shop" : ROOMS "weaponsmith_shop",
]) );
add_exit_alias("enter weaponsmith shop", "weaponsmith shop");
add_exit_alias("enter weaponsmith shop", "weaponsmith");
add_exit_alias("enter weaponsmith shop", "shop");
add_exit_alias("enter weaponsmith shop", "enter shop");
add_exit_alias("enter weaponsmith shop", "north");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
