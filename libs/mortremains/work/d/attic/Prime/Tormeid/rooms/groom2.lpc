// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

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
    "east" : ROOMS(groom1),
  ]) );
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
