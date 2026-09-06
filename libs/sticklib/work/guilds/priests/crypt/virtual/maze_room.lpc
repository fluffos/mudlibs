#include "../DEFS.h"
#include <room.h>

#define EXIT_LIST ({ \
      "north", "south", "east", "west", \
      "northeast", "southeast", "northwest", "southwest", \
});

void add_maze_exit(string* list, int n) {
    string exit;

    exit = list[random(sizeof(list))];
    list -= ({ exit });
    add_exit(exit, ROOM_DIR "maze_" + n);
}

create_room() {
    set_light_level(LT_DARKNESS);
    set(PREVENT_TELEPORT);
    set(ROOM_WD, WD_NONE);
    set_short("Crypt");
}

void setup_room(int n) {
    int i;
    string str, *unused_exits;
    status long_desc_set;

    long_desc_set = 0;
    switch(n) {
    case 1:
	add_exit("south", ROOM_DIR "tunnel2");
	break;

    case N_ROOMS:
	add_exit("northeast", ROOM_DIR "passage1");
	break;

    case N_ROOMS/2:
	// Hauta tahan
	break;

    }

    if(!long_desc_set) {
	switch(random(3)) {
	case 0:
	    str = "You are in an old tunnel somewhere under the city of \
Tristeza. ";
	    break;
	case 1:
	    str = "You are wandering somewhere in the tunnels underneath \
the great Cathedral of Boccob. ";
	    break;
	case 2:
	    str = "An old tunnel. ";
	    break;
	}
	switch(random(3)) {
	case 0:
	    str += "Walls, floor and ceiling are made of large granite \
stones. ";
	    break;
	case 1:
	    str += "Here the tunnel has been mined directly into the rock, \
but parts of the ceiling are made of large stones. ";
	    break;
	case 2:
	    str += "Damp stonewalls are made of large stones. ";
	}

	set_long(str);
    }

    unused_exits = EXIT_LIST;
    if(query_exits()) unused_exits -= m_indices(query_exits());
    // With these two lines we can make it sure that there will
    // always be a way through the maze
    if(n<N_ROOMS) add_maze_exit(&unused_exits, n+1);
    if(n>1) add_maze_exit(&unused_exits, n-1);
    i = sizeof(unused_exits);
    i -= random(2*i/3);
    while(--i>=0)
	add_maze_exit(&unused_exits, 1+N_ROOMS/4+random(N_ROOMS/2));
}
