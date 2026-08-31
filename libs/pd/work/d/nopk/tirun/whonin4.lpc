#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("west Honin Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun. Some distance east of here is the Tirun Market. Far to the west, "
      "above the city gates, a great mountain range can be seen.  Ancient stones "
      "underfoot run north, south, east, and west, making the road easy to "
      "traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  A dark road intersects Honin "
        "here leading north and south into the darkness.  Honin continues east "
        "and west.  The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["east" : ROOMS"whonin3",
                "west" : ROOMS"whonin5",
                "south"  : ROOMS "sxelan1",
                "north"  : ROOMS "nxelan1",
]) );

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads west and east through town.",
          "juncture" : "The central square of Tirun."]) );
}

