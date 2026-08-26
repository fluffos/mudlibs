// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
To your west lies a quaint little shop in the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "west" : ROOMS(shop) ,
  "north" : ROOMS(bshall1),
  "south" : ROOMS(bshall3),
  ]) );
  set("item_desc", ([
  ]) );
  ::create();
}
