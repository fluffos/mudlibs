#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("In the ruined hull of a ship");
    set_long("This is the ruined hull of an old ghost ship.  The pirates that were aboard "
      "died when the ship crashed into a sandbar leaving the ship destroyed.  A mast "
      "with tattered black flags sits in the center of the room.");
    set_items(([
	"mast" : "A tall wooden mast with a crow's nest atop.",
	"flags" : "Black flags with a red sword depicted."
      ]));
    set_exits(([
	"out" : "/d/freepk/keys/great_sand/sand1",
	"north":"/d/freepk/keys/great_sand/wreck2"
      ]));
}

int enter(string str) {
    if (!str || str == "") return 0;
    if (str != "mast") return 0;
    this_player()->move_player("/d/freepk/keys/great_sand/nest", "mast");
    return 1;
}

void init() {
    ::init();
    add_action("enter", "climb");
}

void reset() {
    if (!present("sailor"))
	new("/d/freepk/keys/great_sand/sailor")->move(this_object());
}
