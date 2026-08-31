#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("East Honin Road.");
    set_long(
      "Honin Road is a highly-traveled road that runs west and east through "
      "Tirun.  Some distance west of here is the Tirun Market.  Far to the east "
      "the city gates can be seen.  A dominating marble building is to the north. "
      " To the south sit a small cathedral. Ancient stones underfoot run east and "
      "west, making the road easy to traverse. ");
    set_night_long(
        "Honin Road is mostly deserted at night.  To the north and south, shadows of a "
        "building form in the darkness. The road continues to the east and west. "
        " The stones underfoot are hard to make out in the dark. ");
    set_exits( 
              (["east" : ROOMS"ehonin5",
                "west" : ROOMS"ehonin3",
                "enter mage hall"  : ROOMS "mage/mage_join",
                "enter clergy hall"  : ROOMS "clergy/clergy_join",
]) );
add_exit_alias("enter clergy hall", "clergy hall");
add_exit_alias("enter clergy hall", "clergy");
add_exit_alias("enter mage hall", "mage");
add_exit_alias("enter mage hall", "mage hall");

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Honin Road leads west and east through town.",
          "juncture" : "The central square of Tirun."]) );
}

