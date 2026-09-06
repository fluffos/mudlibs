#include <mxp.h>

inherit "/lib/room";

string query_door_state();

void create_room() {
    set_lumens(1);

    set_brief("Down the well");

    set_description(
	"You are down the well. It is wet and slippery. There is a " +
	MXPTAG("send 'look at &text;'") + "lever" + MXPTAG("/send") +
	" beside a " + MXPTAG("send 'look at &text;'") + "door" +
	MXPTAG("/send") + " to the " + MXPTAG("send") + "west" +
	MXPTAG("/send") + "."
      );

    set_items( ([
	"lever": "The lever can be moved between two positions.",
	"door": #'query_door_state
      ]) );

    set_exits( ([
	"up": "/room/narr_alley"
	, "north": "/room/maze1/maze1"
      ]) );

    set_commands( ([
	"west": "west"
	, "open": "open"
	, "close": "close"
	, "pull": "pull"
	, "turn": "pull"
	, "move": "pull"
      ]) );
}

string query_door_state()
{
    if ("room/sub/door_trap"->query_west_door()) {
	return "The door is closed.";
    }

    return "The door is open.";
}

string query_description() {
    return sprintf("%s %s"
	, ::query_description()
	, funcall(#'query_door_state)
      );
}

int west()
{
    if ("room/sub/door_trap"->query_west_door() == 0) {
	this_player()->move_player("west#/room/sub/door_trap");
	return 1;
    }

    write("The door is closed.\n");
    return 1;
}

int close(string str)
{
    if (!str && str != "door") {
	return notify_fail("Close what?\n"), 0;
    }

    write("You can't.\n");
    return 1;
}

int open(string str)
{
    if (!str && str != "door") {
	return notify_fail("Open what?\n"), 0;
    }

    write("You can't.\n");
    return 1;
}

int pull(string str)
{
    if (!str || str != "lever") {
	return notify_fail(sprintf("%s what?\n"
	    , capitalize(query_verb()))), 0;
    }

    "room/sub/door_trap"->toggle_door();

    return 1;
}
