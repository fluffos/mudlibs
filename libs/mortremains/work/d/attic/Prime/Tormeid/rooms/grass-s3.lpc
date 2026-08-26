// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Outside the castle wall.");
  set("long", @ENDLONG
You are standing just outside the castle wall, on the lush green grass
between the wall and the moat.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "north" : ROOMS(grass-s2),
    "south" : ROOMS(grass-s4),
  ]) );
  set("item_desc", ([
  "wall" : "You stand just outside the castle wall.\n",
  "castle" :"You stand just outside the castle wall.\n",
  "wall" :"It protects the castle from invaders.\n",
  "moat" :"It's a murky green color.\n",
  "grass" : "It's lush and green.\n",
  ]) );
  set("objects", ([
    "boy" : MON(young_boy),
  ]) ) ;
  ::create();
}
