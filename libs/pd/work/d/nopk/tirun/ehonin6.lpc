#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("South Veros Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun. A stable is to the south.  To the east the Gate of Dawn can be "
      "seen.  Ancient stones underfoot run east and west, making the road easy "
      "to traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  To the south the shadow of a "
        "building forms in the darkness. The road continues to the east and west. "
        " The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["west" : ROOMS"ehonin5",
                "east" : ROOMS"egate",
                "enter stable" : ROOMS"eranch",
]) );
add_exit_alias("enter stable", "stable");
add_exit_alias("enter stable", "enter");
    add_pre_exit_function("east", "go_east");

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads to Arulo Juncture west and out "
            "of town east.",
          "juncture" : "The central square of Tirun."]) );
}
int go_east() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
