#include <room.h>
#include <areas.h>

void create_room() {
    set_short("A small lobby");
    set_long(
      "You have entered a rather small but comfortable lobby. A large wooden "
      "staircase leads up to the second floor of the tower. "
      "A large desk stacked with papers stands in the center of the room. "
    );
    set_items(([
	"desk" : "It is filled with records of purchases and many names, "
	"some scribbled and some written neatly. On closer inspection, "
	"you notice that the papers are quite dusty and haven't been moved "
	"at all. "
      ]));
    set_exits(([ 
	"northeast" : AREA_TRISTEZA+"virtual/S1_13",
	"up" : AREA_TRISTEZA+"virtual/sage_room",
      ]));
}
