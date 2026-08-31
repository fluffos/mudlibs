#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("The mountains base begins here.  Looking up, you can "
      "see various paths up the sides of the mountain.  The path continues "
      "along the base of the mountain.");
    set_exits(([
	"southwest":ROOMS"sr2",
	"east":ROOMS"sr4",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
	({"path", "paths"}):"There seems to be several paths that lead up "
	"the side of the mountain.",
      ]));
}

void init() {
    ::init();
    add_action("climb_up", "climb");
}

int climb_up(string s) {
    if(!s || s != "mountain") return notify_fail("Climb what?\n");
    if(!present("ice pick", this_player()) || !present("ice boots", this_player())) { 
	write("You slip and fall down the ice.  Perhaps you should have came prepared.");
	say(this_player()->query_cap_name()+" slides down the side of the mountain.\n");
	return 1;
    }
    write("Using the ice equipment, you trek up the mountain with ease.");
    this_player()->move_player(ROOMS"mt/p1", "up the mountain.");
    return 1;
}

