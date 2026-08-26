
#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "The Front Desk");
    set("long", wrap(
	"You are standing at the front desk, where basic "+
	"is stationed. Beyone the huge granite desk, to the north, "+
	"are the elevators. To the south, you can return to "+
	"the main lobby."
      ) );
    set("exits", ([
      "south" : FLOOR_1("lobby"),
      "north" : FLOOR_1("elevators"),
    ]) );
    set("objects", ([
      "oscar" : MS_MON("sec_guard"),
    ]) );
    reset();
}

/* EOF */
