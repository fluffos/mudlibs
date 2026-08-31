//  Whits House

#include <std.h>
#include <daemons.h>

inherit ROOM;

void create() {
    ::create();
    set_name("whits house");
    set_short("Whit's House");
    if("/wizards/whit/house/room1"->query_open()) 
	add_exit("/wizards/whit/house/room1", "south");
    set_exits(([ "north":"/wizards/whit/house/room3"]));
    set_items(([
	"pedistal":"A keyhole is on top of the pedistal.  It looks like "
	"it might control the doorway to the south.\n",
      ]));
}

string query_long() {
    return "The tunnel is larger than the beginning of the tunnel.  "
    "The tunnel continues to run to the north and south.  There is "
    "a small pedistal to the south near the doorway.  Several drums "
    "of wine lay about the room.";
}

void reset() {
    ::reset();
    if(!"/wizards/whit/house/room1"->query_open()) remove_exit("south");
}

