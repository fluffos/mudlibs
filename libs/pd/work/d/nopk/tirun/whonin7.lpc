#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("West Honin Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun. A stable is to the north.  To the west, above the city gates, "
      "a great mountain range can be seen.  Ancient stones underfoot run east "
      "and west, making the road easy to traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  To the north the shadow of a "
        "building forms in the darkness. The road continues to the east and west. "
        " The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["west" : ROOMS"wgate",
                "east" : ROOMS"whonin6",
                "enter stable" : ROOMS"wranch",
]) );
add_exit_alias("enter stable", "stable");
add_exit_alias("enter stable", "enter");
    add_pre_exit_function("west", "go_west");

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads to Arulo Juncture east and out "
            "of town west.",
          "juncture" : "The central square of Tirun."]) );
}
int go_west() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
