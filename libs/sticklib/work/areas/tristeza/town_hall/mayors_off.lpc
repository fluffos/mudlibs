#include <room.h>

#include "DEFS.h"
void
reset_room()
{
    if (!find_living("village_mayor"))
	(clone_object(THALL_NPC "mayor")) -> move_player("foo",
	  this_object());
}

void
create_room()
{
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(IN_CITY);
    set_short("The mayor's office");
    set_long(
      "This is the mayor's office. Here the mayor reads his newspaper, takes a nap,\
 and performs other mayorly duties. The office has a large window that lights\
 the room nicely, and through it you can see the river and even further away\
 the dark forest. Otherwise it is quite sparsely furnished, but it has a large\
 desk, and a very comfortable looking chair.");
    set_exits(([
	"south"	: THALL_ROOMS "secr_room"
      ]));
    set_items(([
	"window" : "A very large window with a beautiful view.",
	"desk" : "An empty large desk.",
	"chair" : "It's a very comfortable looking comfy chair."
      ]));
    reset_room();
}
