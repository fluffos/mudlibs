// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A smoking den.") ;
  set("long", @ENDLONG
This comfortable lounge is where people come to relax and smoke
whatever they smoke.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(uhall2),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
  "lord" : MON(lord_vargas),
 ]) );
  ::create();
}
