#include <mudlib.h>
inherit ROOM;
inherit DOORS;
void create() {
  seteuid(getuid());
  set("light", 1 );
  set("short", "The main passage.");
  set("long", @ENDLONG
This large stone passage appears well used.
From here you can still see the light of the outside world.
This appears to be the main passage around this area.
ENDLONG
  );
  set( "item_desc", ([
    "walls" : "They are made of large blocks of brown stone.\n",
    "wall" : "They are made of large blocks of brown stone.\n",
    "floor" : "It is made of polished stone, worn by the passage of many feet.\n",
    "stone" : "It is dark brown and rough to the touch.\n",
  ]));
  set( "smell", ([ "defualt" : "You smell the outside air on a gentle breeze.\n",
  ]));
  set("listen", (["default" : "You can hear very little from here.\n",
  ]));
  set("exits", ([
    "southwest" : "d/Dark/Nest/level1/main2",
    "southeast" : "d/Dark/Nest/level1/main3",
    "north" : "d/Dark/Nest/level1/second_hall",
  ]));
::create();
create_door("north", "south", "It's a large metal door", "locked", "none", 30);
}
