#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Gendor");

  set("light", 0);


  set("short", "In the temple.");

set("long", @ENDLONG
This room is unlike the rest you have been in.  There are religous incantations
and symbols throughout the room.  The room is lit by candles, creating eerie
shadows on the walls.  The walls of the room are curved, creating an oval shape.
ENDLONG
   );

  set("item_desc", ([
        "incantations" : "They are in an incomprehensible language.\n",
								"symbols" : "They look like runes of some sort.\n",
								"candles" : "Thick, white, 18-inch, tapered candles light the room.\n",
								"shadows" : "The light from the candles cast wierd shadows apon the room.\n",
   ]) );

  set("smell", ([
    "default" : "It smells like incense and other assorted herbs.\n",

  ]) );

  set("exits", ([
    "north" : ROOMS(ntemple2),
    "south" : ROOMS(temple4),
    "east" : ROOMS(ntemple3),
          ]) );
set("objects", ([
    MON(gmummy) : 2,
  ]) );


  ::create();
}