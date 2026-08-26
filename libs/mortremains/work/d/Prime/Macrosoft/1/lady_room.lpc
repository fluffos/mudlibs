// Cyanide, 4 Aug 99

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "The Ladys' Room");
    set("long", wrap(
	"You are in the pink-tiled lady's room. There are sinks "+
	"against the west wall and stalls against the north wall."
      ) );
    set("exits", ([
      "north" : FLOOR_1("restrooms"),
      "south" : FLOOR_1("l_stall"),
    ]) );
    set("item_desc", ([
        "sinks" : "They're just your basic sinks.\n",
        "urinals" : "Bleh. Why bother?\n",
        "stalls" : "They are to the east.\n",
    ]) );
    set("smell", "It smells like a bathroom. Phew!\n");
}

/* EOF */
