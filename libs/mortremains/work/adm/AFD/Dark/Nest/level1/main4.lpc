#include <mudlib.h>

inherit ROOM;

void create () {
  seteuid(geteuid());

  set ( "light", 1);
  set ( "short", "The main passageway.");
  set ( "long", @ENDLONG
This large stone passageway appears to be well used.
It appears to be the main passage around this area.
ENDLONG
);

  set ( "item_desc", ([
    "floor" : "The floor is polished stone, scuffed by the passage of many feet.\n",
    "walls" : "The walls are made of a dark brown stone.\n",
    "wall" : "The walls are made of a dark brown stone.\n",
  "stone" : "The stone is dark brown and rough to the touch.\n",
]));

  set ( "search_desc", ([
]));
  set ( "smell", ([ "default" : "The air smells slightly musty.\n",
]));
  set ( "listen", ([ "default" : "It's very quiet in here.\n",
    "floor" : "You hear footfalls nearby",
]));
  set ( "exits", ([
    "east" : "d/Dark/Nest/level1/central_hall",
    "north" : "d/Dark/Nest/level1/main2",
    "southeast" : "d/Dark/Nest/level1/main6",
]));
::create();
}
