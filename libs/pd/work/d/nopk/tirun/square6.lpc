#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("%^BOLD%^Tirun Market Square.%^RESET%^\n");
//DO NOT CHANGE THe DESCRIPTION!!!!
    set_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  The large building dominating "
      "the market's southwest corner has %^MAGENTA%^bank%^RESET%^ marked upon it's sign.  The "
      "building to the west has %^GREEN%^a stone carving of a %^RESET%^%^GREEN%^book%^RESET%^ hung over it's double "
      "doors and the building to the south is marked as %^BLUE%^the post office%^RESET%^. "
      " Ancient stone tiles underfoot run north and east making the road easy "
      "to follow. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  Shadows along "
"the side of the road to the south and west coalesce into buildings.  "
      "The stones underfoot are hard to make out and things look different "
      "in the darkness.  The road seems to travel north and east.  "
      );
    set_exits( ([
       "north" : ROOMS "square7",
       "east" : ROOMS "square5",
       "enter bank" : ROOMS "bank",
       "enter library" : ROOMS "library",
       "enter post office" : ROOMS "post",
    ]) );
add_exit_alias("enter bank", "bank");
add_exit_alias("enter library", "library");
add_exit_alias("enter post office", "post office");

    set_items( ([
        "road" : "Ancient stone tiles pave the road.",
        "shop" : "A place to buy and trade goods.",
        "shops" : "Places to buy and trade goods.",
        "fence" : "A wooden structure.",
        "building" : "A structure made of stone.",
        "square" : "The Market Square of Tirun.",
        "sign" : "A shingle with a painting on it."
    ]) );
}
