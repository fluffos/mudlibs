// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" :ROOMS(bnhall3),
   "east" : ROOMS(liwroom1),
  "south" : ROOMS(bnhall1),
  ]) );
  create_door("east", "west", "A beautiful mahogany door.",
  "locked", "servant_key", 23) ;
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
