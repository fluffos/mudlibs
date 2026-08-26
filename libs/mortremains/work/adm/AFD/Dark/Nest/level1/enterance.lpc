#include <mudlib.h>
inherit ROOM;
inherit DOORS;
void create() {
  seteuid(getuid());
  set("light", 1);
  set("short", "The main entrance.");
  set("long", @ENDLONG
This is the front of a large stone building.
It looks like some kind of temple, but it
only has one set of small wooden doors.  
ENDLONG
  );
  set("item_desc", ([
    "building" : "It's large and made of stone.\n",
    "walls" : "They are made of dark grey stone.\n",
  ]));
  set("smell", (["default": "You smell the dust of the trail.\n",
  ]));
  set("listen", (["default" : "You hear nothing of interest.\n",
  ]));
  set("exits", ([
    "south" : "d/Dark/Nest/level1/first_hall",
    "out" : "u/m/morrigu/workroom",
  ]));
::create();
create_door("south", "north", "It's a heavy wooden door", "locked", "none", 15);
}
