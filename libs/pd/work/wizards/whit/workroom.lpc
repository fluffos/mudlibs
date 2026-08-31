#include <locations.h>
// Coded by Whit
#include <std.h>
inherit ROOM;

void reset() {
    ::reset();
    if(!present("box"))
	new("/wizards/seeker/box")->move(this_object());
   if(!present("portal")) {
	new("/wizards/whit/gportal")->move(this_object());
     new("/wizards/stormbringer/portal")->move(this_object());
}
}

object board;

void create() {
    ::create();
    set_short("Whit's Paradise");
    set_name("Whit's Workroom");
    set_long("%^BLACK%^%^BOLD%^The large room is very dark.  The only light "
      "source that "
      "seems to be here is the one that you carry yourself.  Small cracks "
      "in the ceiling reviel the entire skyline.  A small pedistal sits in "
      "the center of the room.  Upon it seems to be levers and buttons.  "
      "There is a small inscription on the pedistal.");
    set_items(([
	"inscription" : "The inscription says:  Sic Para Bellum",
      ]));
    set_properties(([
        "no attack": 1,
	"no scry": 1,
	"light": 3,
	"night light": 3,
      ]));
    set_exits(([
	"practice" : "/wizards/whit/test/room",
       "tombar" : "/d/tombar/rooms/1",
	"square" : SQUARE_LOC,
	"citrin" : "/d/citrin/rooms/1",
	"swamp" : "/d/citrin/rooms/swamp/12",
       "lca" : "/d/old/lca/room/present/7"
      ]));
    set_pre_exit_functions( ({"practice","citrin","swamp","lca"}), ({"prevent_go"}) );
    board = new("/std/bboard");
    board->set_name("whits board");
    board->set_long("This is Whit's board.  Post anything that "
      "needs attention brought to Whit.");
    board->set_max_posts(99);
    board->set_short("mystic board of power");
   board->set_edit_ok(({ "whit" }));
    board->set_board_id("mystic");
    board->set_location("/wizards/whit/workroom");
    board->set_id(({ "board", "mystic board" }));
}

int prevent_go() {
    if(!wizardp(this_player())) return 0;
    return 1;
}

