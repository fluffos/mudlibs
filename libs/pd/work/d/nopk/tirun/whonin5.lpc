#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("West Honin Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun. Far to the east is the Tirun Market. Some distance west, above "
      "the city gates, a great mountain range can be seen.  Ancient stones "
      "underfoot run east and west, making the road easy to traverse. ");
    set_night_long(
        "Honin Road is peaceful at night.  The road continues to the east and west. "
        " The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["west" : ROOMS"whonin6",
                "east" : ROOMS"whonin4",
]) );

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads to Arulo Juncture east and out "
            "of town west.",
          "juncture" : "The central square of Tirun."]) );
}
