// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A coatroom.");
  set("long", @ENDLONG
This is the main coatroom for the castle.  Numerous hooks and shelves
line the walls, and hatrack sits in a corner.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "south" : ROOMS(hall1),
  ]) );
  set("item_desc", ([
  "corner" : "In the corner stands a hatrack.\n",
  "walls" :"There are many hooks and shelves lining the walls.\n",
  "hooks" :"They are for hanging clothing up.\n",
  "hatrack" :"It's a tall wooden pole with smaller poles protruding from it, ideal for\nhanging things such as hats.\n",
 "rack" : "It's a tall wooden pole with smaller poles protruding from it, ideal for\nhanging things such as hats.\n",
  "shelves" : "The shelves are for anything that won't go on a hook or the hatrack.\n",
  ]) );
  set("objects", ([
    "butler" : MON(butler),
 ]) );
  ::create();
}
