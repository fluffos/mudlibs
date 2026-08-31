#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_south", "south");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "safe" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Starburst's General Supply Shop");
    set_long(
      "%^MAGENTA%^Starburst's General Supply Store.%^RESET%^\n"
      "Anything ranging from weapons, armour, or treasure of any "
      "value can be sold here."
      );
    set_items(([
	"door" : "It connects this room to Starburst's storage room.",
	"shop" : "The only general supply shop in town."
      ]));
    set_exits(([
        "out" : ROOMS"square8"
      ]));
}

void reset() {
    ::reset();
    if(!present("starburst"))
        new(MOB"starburst")->move(this_object());
}

int go_south() {
    if(!wizardp(this_player())) {
	message("my_action", "You dare not enter Starburst's storage "
	  "area.", this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " begins to leave south then thinks better of it.",
	  this_object(), ({ this_player() }));
	return 1;
    }
    message("other_action", (string)this_player()->query_cap_name()+
      " chuckles at the idea of Starburst's wrath and proceedes south.",
      this_object(), ({ this_player() }));
    this_player()->move_player(ROOMS"storage1", "south");
    return 1;
}
