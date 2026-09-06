#include <global.h>

inherit LIB_ROOM;

int door_is_open = 0;
int door_is_locked = 1;

string query_door_state();

void
create_room()
{
    set_lumens(1);

    set_brief("The Bank");

    set_description(
	"You are in the bank. To the east is a low counter. The counter is "
	"covered with heavy iron bars. On the wall beside the counter, a "
	"door leads further east."
      );

    add_exit("west", "/room/narr_alley");

    set_items( ([
	"counter": "A sign on the counter says 'Closed for reconstruction.'"
	, "door": #'query_door_state
      ]) );

    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "guard" })
	, ({ "set_short", "A guard" })
	, ({ "set_long", "A big and sturdy guard" })
	, ({ "set_level", 11 })
	, ({ "set_hp", 200 })
	, ({ "set_al", 100 })
	, ({ "add_transient_object", ({ "/obj/treasure"
		, ({ "set_id", "key" })
		, ({ "set_alias", "bank key" })
		, ({ "set_short", "A bronze key" })
		, ({ "set_value", 10 })
		, ({ "set_weight", 1 })
	    })
	  })
	, ({ "add_transient_object", ({ "/obj/weapon"
		, ({ "set_name", "shortsword" })
		, ({ "set_alias", ({ "sword", "short sword" }) })
		, ({ "set_short", "A shortsword" })
		, ({ "set_long", "A professional looking short sword, used by \
warriors and guards." })
		, ({ "set_class", 15 })
		, ({ "set_value", 700 })
		, ({ "set_weight", 3 })
	    })
	  })
      }) );

    set_commands( ([
	"open": "open"
	, "unlock": "unlock"
	, "east": "east"
    ]) );
}

void
reset_room()
{
    door_is_open = 0;
    door_is_locked = 1;
}

string
query_door_state()
{
    if (door_is_open) {
	return "The door is open.";
    }

    return "The door is closed.";
}

int
open(string str)
{
    if (str && str != "door") {
	return notify_fail("Open what?\n"), 0;
    }

    if (door_is_open) {
	return notify_fail("The door is already open.\n"), 0;
    }

    if (door_is_locked) {
	write("The door is locked.\n");
	return 1;
    }

    door_is_open = 1;

    write("Ok.\n");
    say(this_player()->query_name() + " opened the door.\n");

    return 1;
}

int
unlock(string str)
{
    if (str && str != "door") {
	return notify_fail("Unlock what?\n"), 0;
    }

    if (door_is_open || !door_is_locked) {
	return notify_fail("The door is open and unlocked.\n"), 0;
    }

    if (!present("bank key", this_player())) {
	if (present("key", this_player()))
	    write("You don't have the right key.\n");
	else
	    write("You need a key.\n");
	return 1;
    }

    door_is_locked = 0;

    write("Ok.\n");
    say(this_player()->query_name() + " unlocked the door.\n");

    return 1;
}

int
east()
{
    if (!door_is_open) {
	write("The door is closed.\n");
	return 1;
    }

    if (present("guard", this_object())) {
	write("The guard bars the way.\n");
	return 1;
    }

    this_player()->move_player("east#room/bankroom");
    return 1;
}

int
query_door()
{
    return !door_is_open;
}

void
open_door_inside()
{
    door_is_locked = 0;
    door_is_open = 1;
}
