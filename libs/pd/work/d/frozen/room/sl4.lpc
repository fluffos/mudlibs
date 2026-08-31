#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("Almost nothing can be seen now.  The mist "
      "covers everything.");
    set_listen("default","The quiet sound of snow falling is all that can be heard.");
   add_pre_exit_function("north", "go_north");
    set_exits(([
	"southeast":ROOMS"sl3",
        "north":"/d/citrin/rooms/void",
      ]));
    set_properties(([
	"no teleport":1,
	"snow":1,
      ]));

}

int go_north() {
   write("An unknown force repels you.");
   say(this_player()->query_cap_name()+" is repeled from going north.\n");
   return 0;
}

