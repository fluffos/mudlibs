// Virtual server taken from tristeza and modified somewhat - Chopin

#include "../DEFS.h"

object *rooms;

void create() {
    rooms = ({ });
}

void reset() {
    rooms -= ({ 0 });
}

object compile_object(string fname) {
    int n;
    object room;

    if(sscanf(fname, ROOM_DIR "maze_%d", n) != 1) {
	return 0;
    }

    if(n<1 || n>N_ROOMS) {
	return 0;
    }

    room = clone_object(MAZE_ROOM_FILE);
    room->setup_room(n);
    rooms += ({ room });
    return room;
}

object *query_rooms() {
    rooms -= ({ 0 });
    return rooms;
}

void do_dest(object x) {
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
