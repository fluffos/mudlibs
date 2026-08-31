#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("East Wayward Avenue.");
    set_long(
      "East Wayward Avenue is lightly traveled.  Houses line the road to the "
      "north and south.  The ancient stones underfoot running east and "
      "west make the road easy to follow.  North of here, one of the houses "
      "has no door and many colours can be seen from within.");

    set_night_long(
      "East Wayward Avenue is peaceful at night.  Shadows to the north and south "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. North of here, one of the houses "
      "has no door and many colours can be seen from within. ");

    set_exits( 
              (["east" : ROOMS"nparthos5",
                "west" : ROOMS"ewayward4",
       "enter wizard hall" : ROOMS"mage/wizard/wizard_join",
]) );
add_exit_alias("enter wizard hall", "hall");
add_exit_alias("enter wizard hall", "wizard");
add_exit_alias("enter wizard hall", "wizard hall");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
