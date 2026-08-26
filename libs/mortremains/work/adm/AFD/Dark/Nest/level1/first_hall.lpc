#include <mudlib.h>
inherit ROOM;
inherit DOORS;
void create() {
  seteuid(getuid());
  set("light" , 1);
  set("short", "The entrance hall.");
  set("long", @ENDLONG
This room looks like the main and only entrance.
The walls are a little low, but you have no problems
getting into the room.  There are no torches on the
walls, but there is plenty of light to see by.
ENDLONG
  );
  set("item_desc", ([
    "walls" : "They are made of dark grey stone.\n",
    "floor" : "It's worn smooth from use.\n",
    "light" : "It's a faint yellow glow coming from nowhere in particular.\n",
  ]));
  set("smell", (["default" : "You smell the dust of the road.\n",
  ]));
  set("listen", (["default" : "You hear the wind howling by outside.\n",
  ]));
  set("exits", ([
    "north" : "u/m/morrigu/Nest/level1/enterance",
    "south" : "u/m/morrigu/Nest/level1/second_hall",
  ]));
::create();
create_door("south", "north", "It's a banded wooden door", "locked", "none", 20);
create_door("north", "south", "It's a heavy wooden door", "locked" ,"none", 15);
}
