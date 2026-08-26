// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid());
  set("short", "Back of the storage room.");
  set("long", @ENDLONG
You stand in the back of the guard storage room.
A menacing staircase leads down into darkness here.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "down" : D(dungeon1),
    "south" : ROOMS(guard_storage),
  ]) );
  set("item_desc", ([
  "stairs" : "They lead down.\n",
  "staircase" : "They lead down into darkness.\n",
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
   WEP(royal_weapon) : random(4) ,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
