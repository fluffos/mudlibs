// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The Royal Gaming Room.");
  set("long", @ENDLONG
You are in the Royal Gaming Room, where the Royal Family comes for
entertainment.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "east": ROOMS(bnhall6),
    "west" : ROOMS(groom2),
  ]) );
  create_door("east", "west", "A beautiful mahogany door.",
    "closed", "--", 23) ;
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
