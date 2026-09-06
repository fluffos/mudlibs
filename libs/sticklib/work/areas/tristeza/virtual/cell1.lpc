#include "../DEFS.h"

#include <door_defs.h>
#include <room_defs.h>

inherit TRISTEZA_ROOM_C;

object ob;

void
create_room()
{
    ::create_room();
    set_short("Cell");
    set_long( "You feel depressed, for you are in a cold, dark and damp\
 dungeon. The floor is rough, cold stone. There are rings in the walls, into\
 which troublesome prisoners can be chained.");
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);

    (ob = clone_object(DOOR_FILE)) -> add_door(
      "It's a reinforced heavy metal cell door.",
      "north", CITY_DIR+"dungeon1", "crude steel",
      "jail_key", 1, 1, 1, 1000,
      "That is a magical lock. I bet no one can pick that!"
    );
}

void
init_room()
{
    add_action("filter", "", 1);
}

/* Filter out all fun commands. */
int
filter(string arg)
{
    if (member(({"sit", "rest", "sleep", "snore" }), query_verb()) != -1) {
	this_player()->tell_me("The rough, cold stone is too uncomfortable for that.\n");
	return 1;
    }

    if (member(({
	  "applaud", "bounce", "cackle", "caress", "cheer", "chuckle",
	  "comfort", "curtsey", "dance", "flip", "french", "giggle",
	  "handkiss", "happy", "horny", "hug", "kiss", "lick",
	  "laugh", "love", "nudge", "purr", "smile", "squeeze", "tap",
	  "thank", "tickle", "uraa", "whistle", "wiggle",
	  "wink", "worship", "yodel"}), query_verb()) != -1) {
	this_player()->tell_me("You feel so depressed. Can't do that.");
	return 1;
    }

    return 0;
}
