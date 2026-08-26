// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "A hallway in the royal chambers.");
  set("long", @ENDLONG
You stand in an ornately decorated hallway in the royal chambers.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "west" : ROOMS(rhall3),
  "east" : ROOMS(rliving1),
  ]) );
 create_door("east", "west", "A beautiful gold door.", "locked",
   "royal_key", 24) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
