// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.") ;
  set("long", @ENDLONG
You are on the ramparts of the castle wall.
ENDLONG
  );
  set_outside("Light") ;
  set("exits", ([
  "south" : ROOMS(rampart6),
  "north" : ROOMS(rampart8),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
