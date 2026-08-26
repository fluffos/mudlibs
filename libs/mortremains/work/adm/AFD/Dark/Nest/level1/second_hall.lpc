#include <mudlib.h>
inherit ROOM;
inherit DOORS;
void create() {
  seteuid(getuid());
  set("light", 1);
  set("short", "The entrance hall.");
  set("long", @ENDLONG
This hallway appears to be the only way into or
out of this building.  It's low stone walls make
it even more oppressive.  It's light in here, but
there are no torches on the walls.
ENDLONG
  );
  set("item_desc", ([
    "walls" : "They are made of a dark brown stone.\n",
    "light" : "It seems to be coming from nowhere in particular.\n",
    "floor" : "It is well worn from use.\n",
  ]));
set("smell", (["default" : "It's dusty in here.\n",
]));
  set("listen", (["default" : "You hear the wind from outside.\n",
  ]));
  set("exits", ([
    "north" : "d/Dark/Nest/level1/first_hall",
    "south" : "d/Dark/Nest/level1/main1",
  ]));
::create();
create_door("south", "north", "It's a heavy metal door", "locked", "none", 30);
create_door("north", "south", "It's a banded wooden door", "locked", "none", 20);
}
