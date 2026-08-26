// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A bedroom.") ;
  set("long", @ENDLONG
You stand in a bedroom on the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "south" : ROOMS(uhall10),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
   "girl" : MON(little_girl),
   "mom" : MON(mother),
 ]) );
  ::create();
}
