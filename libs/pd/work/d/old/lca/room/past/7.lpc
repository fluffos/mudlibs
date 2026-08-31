//  Created by Whit
//  City of Ages

#include <lca.h>

inherit LCA;

void create() {
    object b;
    ::create();
    set_name("lca square");
    set_short("Unknown Square");
    set_long("Peace and tranquility surround the center of "
      "hustle of the city.  Several benches have been set "
      "around the square for weary travellers to rest.  "
      "A board sits in the center of the square for all "
      "those that would like to post about there "
      "adventurers.");
    set_properties(([ "light":2, "night light":1, ]));
    set_exits(([
	"east":PAST"8",
	"west":PAST"6",
	"north":PAST"4",
	"south":PAST"12",
      ]));
    b = new("/std/bboard");
    b->set_name("board");
    b->set_short("board of fallen dreams");
    b->set_long("The board is used to allow adventurers "
      "to post information about their travels.");
    b->set_board_id("lca");
    b->set_edit_ok(({ "whit", "stormbringer" }));
    b->set_location(PAST"7");
    b->set_max_posts(100);
}

