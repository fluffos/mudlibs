// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room) ;

void create() {
  seteuid(getuid());
  set("short", "An intersection between hallways.") ;
  set("long", @ENDLONG
You stand at an intersection in the hallways of the second floor
of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "west" : ROOMS(uhall7),
  "east" : ROOMS(uhall9),
  "north" : ROOMS(bnhall1),
  "south" : ROOMS(bshall1),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
