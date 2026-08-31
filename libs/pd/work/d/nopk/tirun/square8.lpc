#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("%^BOLD%^Tirun Market Square.%^RESET%^\n");
//DO NOT CHANGE THE DESCRIPTION!!!!
    set_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  %^ORANGE%^A giant shield%^RESET%^ has been "
      "mounted above the entrance of the building to the north, %^BOLD%^%^BLACK%^a massive "
      "broadsword%^RESET%^ is braced diagonally above the entrance to the building "
      "to the west and %^CYAN%^a large carving of a bag and scroll%^RESET%^ hangs above the "
      "entrance to the buiding northwest.  Ancient stone tiles underfoot run "
      "north and east making the road easy to follow. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  Shadows along "
    "the side of the road to the north and west coalesce into buildings.  "
      "The stones underfoot are hard to make out and things look different "
      "in the darkness.  The road seems to travel south and east. "
      );
    set_exits( ([
       "enter armour shop" : ROOMS "armour",
       "south" : ROOMS "square7",
       "enter weapon shop" : ROOMS "weapon",
       "east" : ROOMS "square1",
       "enter supply shop" : ROOMS "supply",
    ]) );
add_exit_alias("enter armour shop", "armour shop");
add_exit_alias("enter weapon shop", "weapon shop");
add_exit_alias("enter supply shop", "supply shop");
add_exit_alias("enter armour shop", "armour");
add_exit_alias("enter weapon shop", "weapon");
add_exit_alias("enter supply shop", "supply");

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
