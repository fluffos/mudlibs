#include <room.h>
#include <areas.h>

#include <city_name.h>
#include <generic_items.h>
#include <generic_npcs.h>

void
create_room()
{
    set_short("Tower");
    set_long("This is the tower beside the temple yard. You can see\
 market square of "+CITY_NAME+" south from here. There is a door to the\
 west and a small bell beside it.");
    set_items(([
	({ "bell", "bronze bell" }) : "You might be able to ring it.",
	({ "city", CITY_NAME }) :
	"You see the market square and some buildings around it",
	"door" : "It's a small wooden door."
      ]));
    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(IN_CITY);
    set(ROOM_WD, WD_INDOORS);
    add_object(GENERIC_BELL, 0, 1);
    add_monster(GENERIC_NPC_HUNCHBACK,
      "Hunchback arrives.\nHunchback scratches his back.", 1);
    set_commands(([
	"west"	: "west",
	"ring"	: "ring",
	"use"	: "ring"
      ]));
    set(NO_CLEANUP);
}

varargs string
query_long(string str, object who)
{
    if (str == "door") {
	if (!(AREA_TRISTEZA+"rooms/elevator")->query_closed_door()
	  &&(AREA_TRISTEZA+"rooms/elevator")->query_level())
	    return "The door is open.";
	else return "The door is closed.";
    }
    return ::query_long(str, who);
}

status
west()
{
    if ( (AREA_TRISTEZA+"rooms/elevator")->query_closed_door() ||
      (int)(AREA_TRISTEZA+"rooms/elevator")->query_level() != 3) {
	this_player()->tell_me(
	  "The door is closed. Ring bell to call the boy.");
	return 1;
    }
    this_player() ->  move_player("west", AREA_TRISTEZA+"rooms/elevator");
    return 1;
}

status
ring(string str)
{
    if (str != "bell") return notify_fail("Ring what?\n"), 0;
    this_player()->tell_me("Ok.");
    (AREA_TRISTEZA+"rooms/elevator")->tell_here(
      "Bell rings.\nBoy makes a note in his notebook.");
    (AREA_TRISTEZA+"rooms/elevator")->call_elevator(3);
    return 1;
}

