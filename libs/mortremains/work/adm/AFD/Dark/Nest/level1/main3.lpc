#include <mudlib.h>
inherit ROOM;
void create() {
  set( "light" , 1);
  set( "short" , "The main passage.");
  set( "long" , @ENDLONG
This large stone passage appears well used.
It appears to be the main passage around this area.
ENDLONG
);
  set( "item_desc", ([
    "walls" : "They are made of large blocks of dark brown stone.\n",
    "wall" : "They are made of large blocks of dark brown stone.\n",
    "floor" : "It is made of polished stone, scuffed by the passage of many feet.\n",
    "stone" : "It is dark brown and rough to the touch.\n",
  ]));
  set("smell", (["default" : "The faint scent of incense wafts through the room.\n",
  ]));
  set( "listen" , ([ "default" : "You hear chanting somewhere in the distance.\n",
  ]));
  set( "exits" , ([
    "south" : "d/Dark/Nest/level1/main5",
    "southwest" : "d/Dark/Nest/level1/central_hall",
    "northwest" : "d/Dark/Nest/level1/main1",
  ]));
::create();
}
