// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A small library.") ;
  set("long", @ENDLONG
You stand in a small library on the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "south" : ROOMS(uhall3),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
  "reynold" : MON(reynold),
 ]) );
  ::create();
}
