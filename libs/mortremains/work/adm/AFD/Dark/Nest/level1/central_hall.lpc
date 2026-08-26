#include <mudlib.h>

inherit ROOM;
void create() {
  seteuid(geteuid());

  set ( "light", 1);
  set ( "short", "The central hall");
set ("long", @ENDLONG
This is a large room resmbling a church or temple's main worshipping area.
There are rows of seats in front of a large altar.
You get the feeling that this is an unholy, ungodly place.
ENDLONG
);

  set ( "item_desc", ([
"seats" : "These are rows of bench seats to sit in.\n",
  "altar" : "This low marble altar is set a short way above the rest of the room.\n"
]));

  set ( "search_desc",([
  "altar" : "It's smooth and has traces of a thick, red fluid on it.\n"
]));

  set ( "smell", ([ "default" : "The faint odor of incense wafts through the room.\n",
"altar" : "It smells rank and of death.\n"
]));
  set ( "listen", ([ "default" : "You hear only silence.\n",
  "altar" : "It doesn't say much.\n",
  "altar" : "It's doesn't say much"
]));
  set ( "exits", ([
    "west" : "d/Dark/Nest/level1/main4",
    "northwest" : "d/Dark/Nest/level1/main2",
    "southwest" : "d/Dark/Nest/level1/main6",
    "southeast" : "d/Dark/Nest/level1/main7",
    "northeast" : "d/Dark/Nest/level1/main3",
    "east" : "d/Dark/Nest/level1/main5",
]));
::create();
}
