// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The war room.") ;
  set("long", @ENDLONG
This is where the people responsible for the defense of the castle
come to discuss and plan actions involving the castle's safety.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(uhall1),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
