#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("West Honin Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun.  Some distance east of here is the Tirun Market.  Far to the west, "
      "above the city gates, a great mountain range can be seen.  A restaurant "
      "is to the north.  Ancient stones underfoot run east and west, making the "
      "road easy to traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  To the north the shadow of a "
        "building forms in the darkness. The road continues to the east and west. "
        " The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["west" : ROOMS"whonin4",
                "east" : ROOMS"whonin2",
                "enter restaurant" : ROOMS"restaraunt",
                "enter bakery" : ROOMS"bakery",
]) );
add_exit_alias("enter restaurant", "restaurant");
add_exit_alias("enter bakery", "bakery");

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads to Arulo Juncture east and out "
            "of town west.",
          "juncture" : "The central square of Tirun."]) );
}
