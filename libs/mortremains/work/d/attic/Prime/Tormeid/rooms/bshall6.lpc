// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
    seteuid(getuid());
    set("short", "A large hallway.");
    set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
To the east are the Commoner living areas.
To the west is the Drunken Ass, the commoners' pub.
ENDLONG
    );
    set("light", 1);
    set("exits", ([
  "west" : ROOMS(pub) ,
  "east" : ROOMS(cs-hall1),
      "south" : ROOMS(s_stairs-2),
      "north" : ROOMS(bshall5),
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
    ]) );
    ::create();
}
