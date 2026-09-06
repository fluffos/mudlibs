#include <global.h>
#include <mxp.h>

inherit LIB_ROOM;

int reboot_time, time_from_reset, last_reset_cycle, lamp_is_lit, list_length;

string query_door_state();
string query_lamp_state();
string query_clock_state();

void
create_room()
{
    reboot_time = time();
    time_from_reset = time();

    set_lumens(1);

    set_brief("Village church");

    set_description(
	sprintf("You are in the local village church. There is a huge pit \
in the center, and a door in the west wall. There is a %s%sbutton%s%s beside \
the door. This church has the service of reviving ghosts. Dead people come \
to the church and %s%spray%s%s. There is a clock on the wall."
	    , "%^BOLD%^%^WHITE%^"
	    , MXPTAG("send 'push &text;' HINT='push button'")
	    , MXPTAG("/send")
	    , "%^RESET%^"
	    , "%^BOLD%^%^WHITE%^"
	    , MXPTAG("send &text;")
	    , MXPTAG("/send")
	    , "%^RESET%^"
	)
      );

    set_items( ([
	"clock": #'query_clock_state
	, "door": #'query_door_state
	, "lamp": #'query_lamp_state
	, "pit": "In the middle of the church is a deep pit. It was used for \
sacrifice in the old times, but nowadays it is only left for tourists to look at."
      ]) );

    add_exit("south", "/room/vill_green");

    set_commands( ([
	"west": "west"
	, "open": "open"
	, "push": "push"
	, "press": "push"
	, "close": "close"
 	, "pray": "pray"
	, "regenerate": "pray"
      ]) );
}

void
reset_room()
{
    if (time_from_reset) {
	last_reset_cycle = time() - time_from_reset;
    }

    time_from_reset = time();
}

string
query_door_state()
{
    if (!"room/elevator"->query_door()
	&& "room/elevator"->query_level(0)) {
        return "The door is open.";
    }

    return "The door is closed.";
}

string
query_lamp_state()
{
    if (lamp_is_lit) {
	return  "The lamp beside the elevator is lit.";
    }

    return  "The lamp beside the elevator is not lit.";
}

string
query_description()
{
    return sprintf("%s %s %s"
        , ::query_description()
        , funcall(#'query_door_state)
        , funcall(#'query_lamp_state)
      );
}

string
query_clock_state()
{
    string ret;
    int i, j;

    ret = "The clock shows ";

    i = time() - reboot_time;
    j = i / 60 / 60 / 24;

    if (j == 1) {
	ret += "1 day ";
    } else if (j > 0) {
	ret += sprintf("%d days ", j);
    }

    i -= j * 60 * 60 * 24;
    j = i / 60 / 60;

    if (j == 1) {
	ret += "1 hour ";
    } else if (j > 0) {
	ret += sprintf("%sd hours ", j);
    }

    i -= j * 60 * 60;
    j = i / 60;

    if (j == 1) {
	ret += "1 minute ";
    } else if (j > 0) {
	ret += sprintf("%d minutes ", j);
    }

    i -= j * 60;

    if (i == 1) {
	ret += "1 second";
    } else if (i > 0) {
	ret += sprintf("%d seconds", i);
    }

    ret += ".\n";

    if (this_player()->query_level() < 20) {
	return ret;
    }

    ret += sprintf("Time since reset is %d seconds.\n"
	, (time() - time_from_reset)
      );

    if (last_reset_cycle) {
	ret += sprintf("Reset cycle: %d\n", last_reset_cycle);
    }

    ret += sprintf("Free block list length: %d\n", list_length);

    return ret;
}

int
west()
{
    if ("room/elevator"->query_door(0) ||
	"room/elevator"->query_level(0) != 2) {
	write("The door is closed.\n");
	return 1;
    }

    this_player()->move_player("west#room/elevator");
    return 1;
}

int
open(string str)
{
    if (str != "door") {
	return notify_fail("Open what?\n"), 0;
    }

    if ("room/elevator"->query_level(0) != 2) {
	write("You can't open the door when the elevator is not here.\n");
	return 1;
    }

    "room/elevator"->open_door("door");
    return 1;
}

int
close(string str)
{
    if (str != "door") {
	return notify_fail("Close what?\n"), 0;
    }

    "room/elevator"->close_door("door");
    return 1;
}

int
push(string str)
{
    if (str && str != "button") {
	return notify_fail(sprintf("%s what?\n"
	    , capitalize(query_verb()))), 0;
    }

    if ("room/elevator"->call_elevator(2)) {
	lamp_is_lit = 1;
    }

    return 1;
}

void
elevator_arrives()
{
    say("The lamp on the button beside the elevator goes out.\n");
    lamp_is_lit = 0;
}

int
pray()
{
    int ret = this_player()->remove_ghost();

    if (ret == 0) {
	write("You pray. Nothing happens.\n");
    }

    return 1;
}

int
prevent_look_at_inv(string str)
{
    return str != 0;
}
