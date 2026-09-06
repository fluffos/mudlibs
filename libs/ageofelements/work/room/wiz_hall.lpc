#include <mxp.h>

inherit "/lib/room";

int lamp_is_lit;

string query_door_state();
string query_lamp_state();

void create_room() {
    set_lumens(1);

    set_brief("Wizard's Hall");

    set_description(
	"The walls of this Wizard's Hall are cast in a glow from the "
	"shimmering field to the north. There is a door to the west "
        "with a " + MXPTAG("send 'push &text;' HINT='push button'") +
        "button" + MXPTAG("/send") + " beside it."
      );

    set_items( ([
	"door": #'query_door_state
	, "lamp": #'query_lamp_state
        , "button": "A button that looks like it wants pressed."
      ]) );

    set_commands( ([
	"west": "west"
	, "open": "open"
	, "close": "close"
	, "push": "push"
	, "north": "north"
      ]) );

    add_transient_object("/room/npc/leo", "Leo arrives in a puff of smoke!");
}

string query_door_state()
{
    if (!"room/elevator"->query_door()
        && "room/elevator"->query_level() == 1) {
        return "The door is open.";
    }

    return "The door is closed.";
}

string query_lamp_state()
{
    if (lamp_is_lit) {
        return  "The lamp beside the elevator is lit.";
    }

    return  "The lamp beside the elevator is not lit.";
}

string query_description()
{
    return sprintf("%s %s %s"
        , ::query_description()
        , funcall(#'query_door_state)
        , funcall(#'query_lamp_state)
      );
}

int open(string str)
{
    if (str != "door") {
	return notify_fail("Open what?\n"), 0;
    }

    if ("room/elevator"->query_level() != 1) {
	write("The door does not open when the elevator is not here.\n");
	return 1;
    }

    "room/elevator"->open_door("door");
    return 1;
}

int close(string str)
{
    if (str != "door") {
	return notify_fail("Close what?\n"), 0;
    }

    "room/elevator"->close_door("door");
    return 1;
}

int west()
{
    if ("room/elevator"->query_door() ||
	"room/elevator"->query_level() != 1) {
	write("The door is closed.\n");
	return 1;
    }

    this_player()->move_player("west#room/elevator");
    return 1;
}

int push(string str)
{
    if (str && str != "button") {
	return notify_fail(sprintf("%s what?\n"
	    , capitalize(query_verb()))), 0;
    }

    if ("room/elevator"->call_elevator(1)) {
	lamp_is_lit = 1;
    }

    return 1;
}

void elevator_arrives()
{
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}

int north()
{
    if (this_player()->query_level() < 21) {
	write("A strong magic force stops you.\n");
	return 1;
    }

    write("You wriggle through the force field...\n");
    this_player()->move_player("north#room/quest_room");

    return 1;
}
