#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("West Honin Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun. Just east of here, teaming with activity, the market square begins. "
      "Far to the west, above the city gates, a great mountain range can be seen. "
      "Ancient stones underfoot run east and west, making the road easy to traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  The shadows to the east suggest a place "
        "of many buildings while to the west the road leads away into "
        "darkness.  The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["west" : ROOMS"whonin2",
                "east" : ROOMS"square7",
]) );

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads to Arulo Juncture east and out "
            "of town west.",
          "juncture" : "The central square of Tirun."]) );
}
