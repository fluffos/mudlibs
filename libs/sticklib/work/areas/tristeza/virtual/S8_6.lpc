#include "../DEFS.h"

#include <generic_rooms.h>
#include <generic_items.h>

inherit TRISTEZA_ROOM_C;

void
create_room()
{
    ::create_room();
    set_short("Market Square of " + CITY_NAME);
    set_items(([
	({ "shop", "tool shop" }) : "You can get tools from it buy typing\
 'get <item>', e.g. 'get stick'.\n\
Type 'list' to see what can be acquired here."
      ]));
    set_long("Northeastern corner of the market square. There is a tool\
 shop here. The " + CITY_NAME + " Bank is to the northeast, the Adventurer's\
 Guild to the east, and the Guild of Races to the north.");
    set_exits(([
	"north" : RACE_GUILD,
	"northeast"     : GENERIC_ROOM_BANK,
	"east"  : ADV_GUILD,
	"southeast"     : CITY_DIR + "S9_7",
	"south" : CITY_DIR + "S8_7",
	"southwest"     : CITY_DIR + "S7_7",
	"west"  : CITY_DIR + "S7_6"
      ]));
    set_commands(([
	"list"  : "list_items",
	"get"   : "get",
	"take"  : "get",
	"enter" : "enter"
      ]));
}

status
list_items()
{
    this_player() -> tell_me(
      "These are the items donated by the Mudional Charity for Players:\n\
\tpointed stick\n\n\
To get these items type 'get <item>' (for example; 'get pointed stick').");
    return 1;
}

status
get(string str)
{
    int i;
    object ob;
    if (!str) return 0;
    if(str != "pointed stick"  && str != "stick")
	return 0;

    if ((i = (int) this_player() -> query_level()) > 5) {
	this_player()->tell_me("But you are a level " + i
	  + " player! You don't need it anymore.");
	return 1;
    }
    if (present("pointed stick",this_player())) {
	this_player()->tell_me("You already have a pointed stick.");
	return 1;
    }

    str = GENERIC_POINTED_STICK;

    if (!this_player()->add_weight((int) (ob = clone_object(str))
	-> query_weight())) {
	this_player()->tell_me("You can't carry any more!");
	destruct(ob);
    } else {
	move_object(ob, this_player());
	this_player()->tell_me("Ok.");
    }
    return 1;
}

status
enter(string str)
{
    if (str != "shop" && str != "tool shop") return 0;
    this_player() -> tell_me("You don't have to enter the shop;\
 just type 'list' to see what items are available.");
    return 1;
}
