// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
To the west is the Commoner Mess Hall.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "west" : ROOMS(comhall1),
 "north" : ROOMS(bshall3),
  "south" : ROOMS(bshall5),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
