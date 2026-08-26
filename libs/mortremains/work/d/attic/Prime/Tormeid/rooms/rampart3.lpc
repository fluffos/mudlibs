// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.") ;
  set_outside("Light") ;
  set("long", @ENDLONG
You are on the ramparts of the castle wall.
ENDLONG
  );
  set("exits", ([
  "north" : ROOMS(rampart4),
  "south" : ROOMS(rampart2),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
