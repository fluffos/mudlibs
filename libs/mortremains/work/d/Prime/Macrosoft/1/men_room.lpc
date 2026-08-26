// Cyanide, 4 Aug 99

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("short", "The Mens' Room");
    set("long", wrap(
	"You are in the blue-tiled men's room. There are sinks "+
	"against the west wall, stalls against the north wall, "+
	"and urinals against the east wall."
      ) );
    set("exits", ([
      "south" : FLOOR_1("restrooms"),
      "north" : FLOOR_1("m_stall"),
    ]) );
    set("item_desc", ([
        "sinks" : "They're just your basic sinks.\n",
        "urinals" : "Bleh. Why bother?\n",
        "stalls" : "They are to the east.\n",
    ]) );
    set("smell", "It smells like a bathroom. Phew!\n");
}

/* EOF */
