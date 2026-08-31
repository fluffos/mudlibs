#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("village shack");
    set_short("village shack");
    set_day_long("Holes in the roof let sunlight in lighting "
      "the room.  Holes in the floor boards lead down to the "
      "earth underneath.  The shack is about to collapse in  "
      "on itself.  An old bed sits on the north wall.  The "
      "window in the shack has been broken out.");
    set_exits(([
	"out":ROOMS"30",
      ]));
    set_smell("default", "A musty smell lingers in the air.");
}

void reset() {
    ::reset();
    if(!present("walking dead"))
	new(MON"walkingdead")->move(this_object());
}

