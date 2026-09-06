#include <global.h>
#include <mxp.h>

inherit LIB_ROOM;

/*
 * This is an elevator.
 * floor 2: church
 */

#define STILL	0
#define DOWN	1
#define UP	2

int level;
int door_is_open;
int time_to_close_door;
int dest;		/* Where we are going. */
int moving_time;	/* How long we are going to move. */
int delay_to_reset;	/* Move back to origin automatically after a delay. */

string query_door_state();
string query_button_state();

void
create_room()
{
    level = 2;
    dest = 2;
    moving_time = 0;

    set_lumens(1);

    set_brief("An elevator");

    set_description(
	"You are in an elevator."
      );

    set_items( ([
	"door": #'query_door_state
	, ({ "button", "buttons" }): #'query_button_state
      ]) );

    set_commands( ([
	"press": "press"
	, "push": "press"
	, "open": "open_door"
	, "close": "close_door"
	, "east": "go_east"
      ]) );
}

void
reset_room()
{
    say("The door swings shut.\n");
    door_is_open = 0;
}

/*
 * Return true if closed door.
 */
int
query_door()
{
    return !door_is_open;
}

string
query_door_state()
{
    if (door_is_open) {
	return "The door is open to the east.";
    }

    return "The door is closed to the east.";
}

string
query_button_state()
{
    string ret = sprintf("On the wall are three buttons, numbered \
%s1%s, %s2%s and %s3%s."
	    , MXPTAG("send 'push button &text;' HINT='push button 1'")
	    , MXPTAG("/send")
	    , MXPTAG("send 'push button &text;' HINT='push button 2'")
	    , MXPTAG("/send")
	    , MXPTAG("send 'push button &text;' HINT='push button 3'")
	    , MXPTAG("/send")
	);

    if (level != dest) {
	ret += sprintf(" Button %d is lit.", dest);
    }

    return ret;
}

string
query_description()
{
    return sprintf("%s %s %s"
	, ::query_description()
	, funcall(#'query_door_state)
	, funcall(#'query_button_state)
      );
}

int
press(string button)
{
    string b;

    if (!button) {
	return notify_fail(sprintf("%s what?\n"
	    , capitalize(query_verb()))), 0;
    }

    if (door_is_open) {
	write("Nothing happens. You wonder, \"Hmm, why?\"\n");
	return 1;
    }

    if (sscanf(button, "button %s", b) != 1) {
	b = button;
    }

    if (moving_time > 0) {
	write("The elevator is still moving.\n");
	return 1;
    }

    if (b == "1" || b == "one") {
	dest = 1;
    } else if (b == "2" || b == "two") {
	dest = 2;
    } else if (b == "3" || b == "three") {
	dest = 3;
    }

    if (dest == level) {
	write("You are already at level " + dest + ".\n");
	return 1;
    }

    if (dest > level) {
	moving_time = dest - level;
	write("The elevator jerks upward.\n");
	say("The elevator jerks upward.\n");
    } else if (level > dest) {
	moving_time = level - dest;
	write("The elevator starts moving downward.\n");
	say("The elevator starts moving downward.\n");
    }

    if (dest == 1 || level == 1) {
	moving_time += 10;
    }

    moving_time += 1;
    set_heart_beat(1);

    return 1;
}

void
heart_beat()
{
    if (time_to_close_door > 0) {
	time_to_close_door -= 1;

	if (time_to_close_door == 0) {
	    say("The door swings shut.\n");
	    door_is_open = 0;
	}
    }

    if (moving_time <= 0) {
	return;
    }

    moving_time -= 1;

    if (moving_time > 0) {
	say("The elevator continues...\n");
	return;
    }

    say("The elevator slows down and stops.\n");
    set_heart_beat(0);
    level = dest;

    if (level == 3) {
	"room/attic"->elevator_arrives();
    } else if (level == 2) {
	"room/church"->elevator_arrives();
    } else if (level == 1) {
	"room/wiz_hall"->elevator_arrives();
    }
}

int
open_door(string str)
{
    if (str != "door") {
	return notify_fail("Open what?\n"), 0;
    }

    if (door_is_open) {
	write("The door is already open!\n");
	return 1;
    }

    if (moving_time > 0) {
	write("The door is stuck.\n");
	return 1;
    }

    door_is_open = 1;
    time_to_close_door = 3;

    write("Ok.\n");
    say(this_player()->query_name() + " opened the door.\n");

    return 1;
}

int
close_door(string str)
{
    if (str != "door") {
	return notify_fail("Close what?\n"), 0;
    }

    if (!door_is_open) {
	write("It is closed!\n");
	return 1;
    }

    door_is_open = 0;
    time_to_close_door = 0;

    write("Ok.\n");
    say(this_player()->query_name() + " closed the door.\n");

    return 1;
}

int
go_east()
{
    if (moving_time > 0) {
	write("You can't use the door  while the elevator is moving.\n");
	return 1;
    }

    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }

    if (level == 2) {
	this_player()->move_player("east#room/church");
    } else if (level == 1) {
	this_player()->move_player("east#room/wiz_hall");
    } else if (level == 3) {
	this_player()->move_player("east#room/attic");
    }

    return 1;
}

int
query_level()
{
    return level;
}

/*
 * This routine is called from various rooms that the elevator connects to.
 */
int
call_elevator(int button)
{
    if (door_is_open) {
	return 0;
    }

    if (moving_time > 0) {
	return 0;
    }

    dest = button;

    if (dest == level) {
	return 0;
    }

    write("A little white lamp beside the button lights up.\n");
    say("A little white lamp beside the button lights up.\n");

    if (dest > level) {
	moving_time = dest - level;
    }

    if (level > dest) {
	moving_time = level - dest;
    }

    if (dest == 1 || level == 1) {
	moving_time += 10;
    }

    moving_time += 1;
    set_heart_beat(1);

    return 1;
}

/*
 * Called by others to see if the elevator is moving
 */
int
is_moving()
{
    if (level == dest) {
	/* Still */
	return 0;
    }

    if (level > dest) {
	/* down */
	return 1;
    }

    /* up */
    return 2;
}
