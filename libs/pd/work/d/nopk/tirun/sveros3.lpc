#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("South Veros Road.");
    set_long(
      "Running north and south through the center of Tirun, Veros Road "
      "stays busy.  Some distance north, the Tirun Market place bustles with "
      "activity.  To the west sits a building, the sign above it's door has "
      "%^ORANGE%^a burning candle%^RESET%^ painted on it.  Far to the south the masts of ships "
      "can be seen above the city walls.  The ancient stones underfoot running "
      "north and south make the road easy to follow. "
);
    set_night_long(
      "Running north and south through the center of Tirun, Veros Road "
      "is peaceful at night.  The shadow of a building can be made out to "
      "the west.  The road leads away into the darkness to the north and "
      "south.  The stones underfoot are hard to make out in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"sveros2",
                "south" : ROOMS"sveros4",
                "enter light shop" : ROOMS"light",
                "enter jail"  : ROOMS"jail"
]) );
add_exit_alias("enter light shop", "light shop");
add_exit_alias("enter light shop", "shop");
add_exit_alias("enter light shop", "light");
add_exit_alias("enter jail", "jail");


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
