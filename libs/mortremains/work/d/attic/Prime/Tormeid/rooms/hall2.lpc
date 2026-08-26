// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "An intersection between two large hallways.") ;
  set("long", @ENDLONG
You stand in a magnificient hallway within the castle.  There seems to
be an audience room to the east.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(hall1),
   "north" : ROOMS(mnhall1),
  "south" : ROOMS(mshall1),
   "east" : ROOMS(hall3) ,
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
