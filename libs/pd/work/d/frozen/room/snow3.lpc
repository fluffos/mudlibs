#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("There is not much to be seen out on the plain.  The path breaks up into "
      "two directions here.  To the northeast, a mountain can be seen.  Nothing but "
      "mist and fog covers the direction to the northwest.");
    set_exits(([
	"south":ROOMS"snow2",
	"northwest":ROOMS"sl1",
	"northeast":ROOMS"sr1",
      ]));
}

