#include <mudlib.h>
inherit ROOM;
void create() {
  seteuid(getuid());
  set("light" , 1);
  set("short" , "The main passage");
  set( "long" , @ENDLONG
This large stone passage appears well used.
It is slightly darker and warmer here.
ENDLONG
);
  set( "item_desc", ([
    "walls" : "The walls are made of a dark brown stone.\n",
    "wall" : "The walls are made of a dark brown stone.\n",
    "floor" : "The floor is scuffed from the passage of many feet.\n",
    ]));
  set( "smell", ([ "default" : "The faint scent of incense wafts through the passage.\n",
]));
  set( "listen", ([ "default" : "You hear muffled voices chanting in the distance.\n",
]));
  set( "exits", ([
    "northwest" : "d/Dark/Nest/level1/main4",
    "northeast" : "d/Dark/Nest/level1/central_hall",
    "southwest" : "d/Dark/Nest/level1/catacomb1",
    "east" : "d/Dark/Nest/level1/main7",
]));
::create();
}
