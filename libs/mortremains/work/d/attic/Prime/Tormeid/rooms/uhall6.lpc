// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room) ;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.") ;
  set("long", @ENDLONG
You stand in a large hallway running east and west through the castle's
second floor.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "south" : ROOMS(bedroom9),
  "north" : ROOMS(bedroom10),
  "west" : ROOMS(uhall5),
  "east" : ROOMS(uhall7),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
