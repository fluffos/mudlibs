// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the northwest tower, 2nd floor.") ;
  set("long", @ENDLONG
You stand in the northwest tower, second floor.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "south" : ROOMS(rampart8) ,
    "down" : ROOMS(nwtower1),
    "up" : ROOMS(nwtower3),
   "east" : ROOMS(rampart9),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "down" : "$N goes down the stairs.",
    "up" : "$N goes up the stairs.",
  ]) );
  ::create();
}
