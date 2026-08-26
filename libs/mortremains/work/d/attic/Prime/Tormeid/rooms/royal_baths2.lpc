// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The royal baths.");
  set("long", @ENDLONG
You stand in the royal baths.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "south" : ROOMS(royal_baths1),
    "east" : ROOMS(royal_baths3),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(naked_lady) : random(6) + 2,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
