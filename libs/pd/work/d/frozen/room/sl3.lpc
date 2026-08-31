#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a path in the snow");
    set_short("a path in the snow");
    set_long("The mist is beginning to get alot thicker.  It is hard to see anything "
      "that is around you.  Perhaps it might be wise to turn around.");
    set_exits(([
	"southeast":ROOMS"sl2",
	"northwest":ROOMS"sl4",
      ]));
    set_properties(([
       "no teleport":1,
       "snow":1,
       ]));

}

