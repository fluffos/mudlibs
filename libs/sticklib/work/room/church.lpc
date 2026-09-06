/*  /room/church.c
**
**  Originally done by Graah and perhaps Frobozz, and I am sure many more
**  had a hand in it =)  I made some changes to bring it more up to date.
**  -Tamarindo
*/

#include <room.h>
#include <areas.h>
#include <daemons.h>
#include <city_name.h>
#include <generic_npcs.h>
#include <generic_rooms.h>
#include <generic_items.h>

#include "/areas/tristeza/DEFS.h"

#undef XMAS

int query_elevator_here();
string query_door_desc();
string query_clock_desc();

void create_room()
{
    set_short("Temple yard");
    set_long(
      "You are in the temple yard, south of the "+CITY_NAME+" temple.  "
      "There is a huge pit in the center and a door in the west wall.  "
      "There is a bell beside the door.  As you look up the west wall "
      "you see it is in fact a tall tower.  There is a clock on the wall."
    );

    set_items( ([
	"pit":
	"In the middle of the yard is a deep pit.  It was used for "
	"sacrifice in the old days, but today it is just left for "
	"tourists to look at.",
	"door":
	#'query_door_desc,
	"clock":
	#'query_clock_desc,
      ]) );

    set_exits( ([
	"north": AREA_TRISTEZA+"temple/temple_ruins",
	"east": RACE_GUILD,
	"south" : AREA_TRISTEZA+"virtual/S7_6",
	"west": GENERIC_ROOM_CHURCH, // a 'dummy' exit; command defined later on.
	"northeast" : AREA_TRISTEZA+"wedding/chapel",
      ]) );

    set_outdoors(WD_NONE);
    set_light_level(LT_LIGHTS);

    set(NO_PK);
    set(IN_CITY);
    set(PREVENT_TELEPORT);

    add_object(GENERIC_FINGER_TOOL, 0, 1);

    add_monster(GENERIC_NPC_SAINT, 0, 1);
#ifdef XMAS
    add_monster(GENERIC_NPC_SAINT_XMAS, 0, 1);
#endif

    set_commands( ([
	"west": "west_cmd",
	"ring": "ring_cmd",
	"pray": "pray_cmd",
      ]) ); 
}

void init_room()
{
    if (interactive(this_player()))
    {
	if (PEACE_D->query_peace())
	    this_player()->tell_me("Peace is upon the world, no \"player killing\"");
    }
}

status query_prevent_shadow() { return 1; }

int query_elevator_here()
{
    return ((int)AREA_TRISTEZA+"rooms/elevator"->query_closed_door() &&
      (int)AREA_TRISTEZA+"rooms/elevator"->query_level() == 2) ? 1 : 0;
}

status west_cmd(string str)
{
    if (#'query_elevator_here)
	this_player()->move_player("west", AREA_TRISTEZA+"rooms/elevator");
    else
	this_player()->tell_me("The door is closed.  Ring the bell to call the boy.");

    return 1;
}

status ring_cmd(string str)
{
    if (str != "bell")
	return notify_fail("Ring what?\n"), 0;

    this_player()->tell_me("You ring the bell.");
    (AREA_TRISTEZA+"rooms/elevator")->call_elevator(2);
    return 1;
}

status pray_cmd(string str)
{
    if(!this_player()->query_ghost())
    {
	this_player()->tell_me("No sense praying unless you're dead.");
	return 1;
    }

    this_player()->remove_ghost();
    return 1;
}

string query_door_desc()
{
    return #'query_elevator_here ? "The door is open." : "The door is closed.";
}

string query_clock_desc()
{
    return "An old archaic clock, showing about "+
    (string)NATURE_D->query_about_time()+".";
}

int query_is_start_location()
{
    return 1;
}
