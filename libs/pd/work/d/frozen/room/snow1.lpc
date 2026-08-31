#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("There is not much to be seen out on the plain.  A small path etches through "
      "the snow covered ground, and to be safe, you decide to stay on the path.");
    set_exits(([
	"south":ROOMS"docks",
	"north":ROOMS"snow2",
      ]));
    set_properties(([
       "no teleport":1,
       "snow":1,
       ]));
}

