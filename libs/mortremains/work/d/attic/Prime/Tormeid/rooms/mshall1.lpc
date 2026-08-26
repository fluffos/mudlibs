// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
This hallway runs north and south through the castle.
A magnificient suit of armor is mounted on the wall here.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(hall2),
  "south" : ROOMS(mshall2),
  ]) );
  set("item_desc", ([
  "wall" : "The armor is firmly mounted on the wall.\n",
  "armor" : "The suit of armor is perfectly polished and mounted on the wall.\n",
    "suit" : @ENDDESC
The suit of armor is perfectly polished and mounted on the wall.
ENDDESC
  ,  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
