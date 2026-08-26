// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the royal baths.");
  set("long", @ENDLONG
You stand in the royal baths.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(royal_baths2),
    "south" : ROOMS(royal_baths4),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(naked_lady) : random(5) + 3,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
