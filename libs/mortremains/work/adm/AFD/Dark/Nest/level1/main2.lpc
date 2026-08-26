#include <mudlib.h>
inherit ROOM;
void create () {
  seteuid(getuid());
  set ( "light", 1);
  set ( "short" , "The main passage.");
  set ( "long" , @ENDLONG
This large stone passageway seems to be well used.
The floor is scuffed by the passage of many feet.
ENDLONG
  );
  set ( "item_desc" , ([
    "walls" : "They are made of large blocks of a dark brown stone.\n",
    "wall" : "They are made of large blocks of a dark brown stone.\n",
    "stone" : "It's dark brown and rough to the touch.\n",
    "floor" : "The polished stone has been scuffed by the passage of many feet.\n",
]));
set ( "smell" , ([ "default": "The faint scent of inscense wafts through the room.\n",
]));
  set ( "listen" , ([ "default": "You hear muffled chanting somewhere in the distance.\n",
]));
  set ( "exits", ([
    "south" : "d/Dark/Nest/level1/main4",
    "northeast" : "d/Dark/Nest/level1/main1",
    "southeast" : "d/Dark/Nest/level1/central_hall",
]));
::create();
}
