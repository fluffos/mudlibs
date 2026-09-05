#include "ansi.h"
inherit "room/room";

void reset (status arg) {
	if(arg) return;
	set_light(1);
	short_desc = HIR+"R"+HIY+"a"+HIG+"i"+HIB+"n"+HIC+"b"+HIM+"o"+BLU+"w "+GRN+"Trail"+NORM;
	items = ({
		"trees","A forest of Gingerbread Plum Trees",
		"house","A two story house made entirely of peanut brittle",
		"trail","A rainbow trail to help you move faster"});
	
	long_desc = 
"   The Rainbow Trail is a shortcut between the Gingerbread Plum Trees\n\
and the Peanut Brittle House.  Sometimes taking this trail is a time\n\
saver, other times you miss out on exciting things!\n";
	dest_dir = ({"players/martha/area/rooms/pbhouse", "north",
				 "players/martha/area/rooms/ptrees", "south"});
}
