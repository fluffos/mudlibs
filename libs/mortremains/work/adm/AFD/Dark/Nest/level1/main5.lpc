#include <mudlib.h>
inherit ROOM;
void create ()  {
  seteuid(getuid());
  set( "light" , 1);
set( "short" , "The main passage." );
  set( "long" , @ENDLONG
This large stone passage appears to be well used.
It appears to be the main passage around this area.
ENDLONG
  );
  set( "item_desc", ([
    "walls" : "They are made of a dark brown stone.\n",
    "wall" : "They are made of a dark brown stone.\n",
    "floor" : "It appears scuffed by the passage of many feet.\n",
  ]));
set( "smell", ([ "default" : "The faint scent of incense wafts through the room.\n",
  ]));
  set( "listen" , ([ "default" : "You hear the faint sound of chanting.\n",
  ]));
  set( "exits", ([
    "west" : "d/Dark/Nest/level1/central_hall",
    "north" : "d/Dark/Nest/level1/main3",
    "southwest" : "d/Dark/Nest/level1/main7",
  ]));
::create();
}
