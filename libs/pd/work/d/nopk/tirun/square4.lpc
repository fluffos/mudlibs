#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("Northern Square");
//DO NOT CHANGE THIS DESCRIPTION!!!!
    set_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  A large building dominates "
      "the market to the far north. The building to the east has %^MAGENTA%^a fish "
      "inside an ale glass%^RESET%^ painted on a sign above the door and the "
      "building to the south has %^ORANGE%^a healer's hand%^RESET%^ painted above the door. "
      " Ancient stone tiles underfoot run north and west making "
      "the road easy to follow. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  Shadows along "
     "the side of the road to the east and south coalesce into buildings.  "
      "The stones underfoot are hard to make out and things look different "
      "in the darkness.  The road seems to travel north and west.  "
      );
    set_exits( ([
       "north" : ROOMS "square3",
       "enter apothecary" : ROOMS "oil_shop",
       "enter tavern" : ROOMS "pub",
       "west" : ROOMS "square5",
    ]) );
add_exit_alias("enter apothecary", "apothecary");
add_exit_alias("enter apothecary", "oil shop");
add_exit_alias("enter apothecary", "herb shop");
add_exit_alias("enter apothecary", "shop");
add_exit_alias("enter tavern", "tavern");
add_exit_alias("enter tavern", "enter pub");
add_exit_alias("enter tavern", "pub");

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
