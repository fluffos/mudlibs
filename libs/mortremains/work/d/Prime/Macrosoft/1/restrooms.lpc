// Template

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "A short hallway");
    set("long", wrap(
	    "This is a short little hallway just leading to the "+
	    "restrooms. The Men's Room is to the north, and the "+
	    "Lady's Room is to the south."
      ) );
    set("exits", ([
      "west" : FLOOR_1("lobby"),
      "north" : FLOOR_1("men_room"),
      "south" : FLOOR_1("lady_room"),
    ]) );
}

/* EOF */
