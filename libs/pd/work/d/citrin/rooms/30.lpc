#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("village streets");
    set_short("village streets");
    set_long("A rundown shack sits to the north of "
      "the dirt street.  Boards and shingles lay cluttering "
      "the yard from the recent storms.  This road travels "
      "from the northeast to the west surrounding the village.  ");
    set_exits(([
	"west":ROOMS"29",
	"northeast":ROOMS"31",
	"enter":ROOMS"shacks/shack1",
      ]));
    set_smell("default", "A musty smell lingers in the air.");
}

void reset() {
    ::reset();
    if(!present("shack")) 
	new(OBJ"shack")->move(this_object());
}
