#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("%^BOLD%^Tirun Market Square.%^RESET%^\n");
//DO NOT CHANGE THIS DESCRIPTION!!!!
    set_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  One large building sits to "
      "the north and east of the road, two doors, one east and one north "
      "lead into the building. The building looks to have some importance."
      "  Ancient stone tiles underfoot run west and south making the road "
      "easy to follow. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  A shadow along "
      "side of the road to the north and east seems to coalesce into a "
      "building.  The stones underfoot are hard to make out and things "
      "look different in the darkness.  The road seems to travel west and south.  "

      );
    add_pre_exit_function("east", "go_east");
    set_exits( ([
       "south" : ROOMS "square3",
       "west" : ROOMS "square1",
       "enter adventurer hall" : ROOMS "adv_enter",
       "enter colosseum" : "/d/arena/bet"
    ]) );
add_exit_alias("enter colosseum", "colosseum");
add_exit_alias("enter colosseum", "enter arena");
add_exit_alias("enter colosseum", "arena");
add_exit_alias("enter colosseum", "e");
add_exit_alias("enter adventurer hall", "adventurer hall");
add_exit_alias("enter adventurer hall", "adventurer");
add_exit_alias("enter adventurer hall", "hall");
add_exit_alias("enter adventurer hall", "n");

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
int go_east() {
if(this_player()->query_mounted()) this_player()->force_me("buck "+this_player()->query_mounted()->query_name());
  return 1;
}
