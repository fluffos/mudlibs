#include <std.h>
#include <citrin.h>

inherit VIRTUALROOM;

mapping get_exits() {
    int x,y,i;
    string xs,ys, fname, *ways;
    mapping out;

    fname = file_name(this_object());
    if(sscanf(fname, "/d/citrin/rooms/lake/%d,%d", x, y) != 2) 
	return (["fname":"/d/tirun/square"]);
    ways = ({});
    if(x>1) ways += ({ "west" });
    if(y>1) ways += ({ "south" });
    if(y<MAX_Y) ways += ({ "north" });
    if(x<MAX_X) ways += ({ "east" });
    i = sizeof(ways);
    out = ([]);
    while(i--) {
	if(ways[i] == "north") out += ([ "north":LAKE+x+","+(y+1), ]);
	if(ways[i] == "south") out += ([ "south":LAKE+x+","+(y-1), ]);
	if(ways[i] == "east") out += ([ "east":LAKE+(x+1)+","+y, ]);
	if(ways[i] == "west") out += ([ "west":LAKE+(x-1)+","+y, ]);
    }
    if(!out || out == ([]) ) return (["none":"/d/tirun/square"]);
    if(x==1 && y == 1) out += (["out":ROOMS"46",]);
    return out;
}

void create() {
    set_server(LAKESER);
    ::create();

    set_exits(get_exits());
    if(query_exit("out")) set_pre_exit_functions( ({"out"}), ({"out"}) );
}

int out() {
    if(random(2)) {
	write("You catch your footing and climb out of the lake.\n");
	return 1;
    }
    write("You cant seem to catch your footing to climb out.\n");
    return 0;
}

