// Virtual server for rooms in the Main Town, the capital of StickLand
//
// V1.0 11-sep-95 by Doomdark

#include "../DEFS.h"

#include <city_name.h>

object *rooms;

void
create()
{
    rooms = ({ });
}

void
reset()
{
    rooms -= ({ 0 });
}

object
compile_object(string fname)
{
    string tmp;
    int x, y;
    object room;

#ifdef DEBUG
    object dd;
    if (dd = find_player("doomdark"))
	dd->tell_me(CITY_NAME ": loading (virtual) room: '"+fname+"'.");

#endif

    if (sscanf(fname, "%s/tristeza/virtual/S%d_%d", tmp, x, y) < 3) {
#ifdef DEBUG
	dd->tell_me("Error: filename '" + fname + "' invalid; sscanf failed.");
#endif
	return 0;
    }

    if (x < SMALLEST_X || x > LARGEST_X || y < SMALLEST_Y || y > LARGEST_Y) {
#ifdef DEBUG
	dd->tell_me("Error: coordinates for the " CITY_NAME " room invalid; x: "
	  + x + ", y: "+y+".");
#endif
	return 0;
    }

    room = clone_object(TRISTEZA_ROOM_C);
    room->setup_room(x, y);
    rooms += ({ room });
    return room;
}

object *
query_rooms()
{
    rooms -= ({ 0 });
    return rooms;
}

void
do_dest(object x)
{
    while (first_inventory(x))
	do_dest(first_inventory(x));
    destruct(x);
}

// With this we can easily destruct all the rooms, if needed...
// Usually only needed during testing, though... :-/
void
destruct_rooms()
{
    int i, j;
    object ob, *x;
    rooms -= ({ 0 });
    i = sizeof(rooms);
    while (i--) {
	if (!objectp(rooms[i])) continue;
	x = all_inventory(rooms[i]);
	j = sizeof(x);
	while (j--) {
	    if (interactive(x[j]))
		move_object(x[j], "/room/church");
	    else do_dest(x[j]);
	}
	destruct(rooms[i]);
    }
    rooms = ({ });
}
