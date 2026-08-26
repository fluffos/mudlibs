// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room) ;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "east" : ROOMS(uhall11),
  "west" : ROOMS(uhall9),
  "north": ROOMS(bedroom14),
  "south" : ROOMS(bedroom13),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
