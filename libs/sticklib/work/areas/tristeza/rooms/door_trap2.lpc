#include <room.h>
#include <areas.h>

void
create_room()
{
    set_short("Black room");
    set_long(
      "The walls, floor, ceiling, and door are all totally black. The\
 sense of power is even stronger here. What could it mean? A\
 narrow stairway leads down through the rock. You are filled\
 with a powerful sense of foreboding. Perhaps it would be wise\
 to turn back now.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_NONE);
    set(IN_CITY);
    set(PREVENT_TELEPORT);
    set_exits(([ "down" : AREA_TRISTEZA+"rooms/door_trap3" ]));
    set_commands(([
	"open" : "door_func",
	"close": "door_func"
      ]));
}

status
door_func(string str)
{
    if ( !str || strstr(str,"door")==-1) return 0;
    this_player()->tell_me("The door is much to heavy.");
    return 1;
}

