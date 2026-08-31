#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("South Veros Road.");
    set_long(
      "Running north and south through the center of Tirun, Veros Road "
      "stays busy.  Some distance north, the Tirun Market place bustles with "
      "activity.  To the east sits a building, the sign above it's door has "
      "%^CYAN%^a book%^RESET%^ painted on it.  To the south the masts of ships "
      "can be seen above the city walls.  The ancient stones underfoot running "
      "north and south make the road easy to follow. "
);
    set_night_long(
      "Running north and south through the center of Tirun, Veros Road "
      "is peaceful at night.  The shadow of a building can be made out to "
      "the east.  The road leads away into the darkness to the north and "
      "south.  The stones underfoot are hard to make out in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"sveros4",
                "south" : ROOMS"sveros6",
       "enter sage hall" : ROOMS"sage_room",
]) );
add_exit_alias("enter sage hall", "sage");
add_exit_alias("enter sage hall", "hall");
add_exit_alias("enter sage hall", "sage hall");

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
