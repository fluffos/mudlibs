#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("village streets");
    set_short("village streets");
    set_long("This is the heart of the small village.  "
      "At one time this was the busiest place for trading.  "
      "Now only silence covers this village.  The dirt "
      "roads that run through the city all meet here.  ");
    set_exits(([
	"southwest":ROOMS"30",
	"east":ROOMS"32",
	"north":ROOMS"26",
      ]));
    set_smell("default", "A musty smell lingers in the air.");
}

