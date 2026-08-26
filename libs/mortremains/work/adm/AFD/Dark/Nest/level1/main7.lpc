#include <mudlib.h>
inherit ROOM;
void create() {
  seteuid(getuid());
  set("light", 1);
  set("short", "The main passage.");
  set("long", @ENDLONG
This large stone passage appears well used.
It is slightly darker and warmer here.
ENDLONG
);
  set( "item_desc", ([
    "walls" : "They are made of large blocks of dark brown stone.\n",
    "wall" : "They are made of large blocks of dark brown stone.\n",
    "floor" : "It is scuffed from the passage of many feet.\n",
  ]));
  set( "smell" , ([ "default" : "The scent of incense wafts through the room.\n",
  ]));
  set( "listen" , ([ "default" : "You hear the faint sound of chanting.\n",
  ]));
  set( "exits" , ([
    "west" : "d/Dark/Nest/level1/main6",
    "northwest" : "d/Dark/Nest/level1/central_hall",
    "northeast" : "d/Dark/Nest/level1/main5",
    "southeast" : "d/Dark/Nest/level1/catacomb3",
  ]));
::create();
}
