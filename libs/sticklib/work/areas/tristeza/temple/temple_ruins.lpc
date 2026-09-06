#include <room.h>
#include <areas.h>
#include <generic_rooms.h>

#include "../DEFS.h"

void
create_room()
{
    set_short("Ruins of the Temple");
    set_long("Once in the golden days this was the place where mortals\
 worshipped their Gods. People lived in harmony and the world was beautiful.\
 Now it is torn apart and so is the Temple.\nThere is a plaque fastened into\
 a wall that hasn't crumbled. \nA small path leads \
east. ");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_OUTDOORS);
    set(IN_CITY);
    set(NO_PK);
    set_items(([
	({ "wall", "walls" }) : "Only one wall stands, and there is a plaque fastened\
 into it.",
	"plaque" : "Administus sit gloria,\nEt Gamus Drivus,\nac Mudlibrarium,\n\
In saeculorum saecula.\nAmen."
      ]));
    set_exits(([
	"north"	: AREA_TRISTEZA+"temple/grave_yard",
	"east" : "/room/path",
	"south"	: GENERIC_ROOM_CHURCH 
      ]));
}

void
init_room()
{
    // Great priests, yeah...
    add_action("disallow", "holocaust");
    add_action("disallow", "purify");
}

status
disallow(string arg)
{
    this_player()->tell_me("Tim the Enchanter glares at you.");
    return 1;
}

status
read_cmd(string str)
{
    if (str == "plaque") {
	this_player()->tell_me(query_long(str, this_player()));
	return 1;
    }
    return 0;
}
