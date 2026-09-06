#include <room.h>
#include <door_defs.h>
#include <areas.h>
#define TP this_player()

void
create_room()
{
    set_short("Black room");
    set_long(
      "This is a black room. The walls are black, the floor is black, the\
 ceiling is black - everything is black. You sense an aura of immense\
 power emanating from this place. There is powerful magic here, but\
 its nature or purpose remains unknown. You notice a faint inscription\
 on one wall.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_NONE);
    set(IN_CITY);
    set(PREVENT_TELEPORT);
    set_items(([ 
	({ "wall", "inscription" }) : "The inscription appears to be\
 very old, but you can still make out the words:\n\n\
	fire\n\
	to begin whipping dance of the dead\n\
	blackened is the end\n\
	to begin whipping dance of the dead\n\
	colour our world blackened" ]));
    set_commands(([ 
	"open" : "door_func",
	"close": "door_func"
      ]));
    add_object( ({ DOOR_FILE,
	({ "add_door",
	  "It is an incredibly thick and heavy stone door.",
	  "west", AREA_TRISTEZA+"rooms/door_trap2", 0,0,0,1 }) }), 0,1);
    add_object( ({ DOOR_FILE,
	({ "add_door",
	  "It is an incredibly thick and heavy stone door.",
	  "east", AREA_TRISTEZA+"rooms/well", 0,0,1,1 }) }), 0,1);
}

void
reset_room()
{
    object door;
    if ( door=present("west door"))
	door->set_closed(0,0,1);
    if ( door=present("east door"))
	door->set_closed(1,0,1);
}

status
toggle_door() 
{
    object door;
    TP->tell_me("You pull the lever.");
    tell_here(TP->query_name()+" pulls the lever.",TP);
    if ( door=present("west door"))
	door->set_closed(!door->query_is_closed(),0,1);
    if ( door=present("east door"))
	door->set_closed(!door->query_is_closed(),0,1);
}

status
door_func(string str)
{
    if ( !str || strstr(str,"door")==-1) return 0;
    this_player()->tell_me("The door is much to heavy.");
    return 1;
}

