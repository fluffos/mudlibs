#include <global.h>

inherit LIB_ROOM;

string query_door_state();

void
create_room()
{
    set_lumens(1);

    set_brief("Backroom of Bank");

    set_description(
	"You are in the backroom of the Bank."
      );

    add_item("door", #'query_door_state);

    add_permanent_object("/obj/safe");

    set_commands( ([
	"west": "west"
	, "open": "open"
      ]) );
}

string
query_door_state()
{
    if ("room/bank"->query_door()) {
	return "The door is closed.";
    }

    return "The door is open.";
}

int
west()
{
    if ("room/bank"->query_door()) {
	write("The door is closed.\n");
	return 1;
    }

    this_player()->move_player("west#room/bank");
    return 1;
}

int
open(string str)
{
    if (!str) {
	return notify_fail("Open what?\n"), 0;
    }

    if (!"room/bank"->query_door()) {
	return 0;
    }

    "room/bank"->open_door_inside();

    say(this_player()->query_name() +
	" opens the door.\n");
    write("Ok.\n");

    return 1;
}
