#include "../defs.h"

inherit ROOM;
inherit DOORS;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
		set("short", "the foyer.");
set("long", @ENDLONG
Apon entering this room, you are greeted by a lovely view.  Crystal statues
stand side by side along the center of the room, forming a walkway.  A dim
light emenates from the statues here, illuminating the room here.
ENDLONG
   );
set("exits", ([
    "west" : ROOMS(vamphall),
    "up" : ROOMS(stair),
    ]) );
set("objects", ([
    OBJ(statue) : 12,
  ]) );
create_door("west", "east", "It's a black iron door.",
    "locked", "bkey", 45);
  ::create();
}

