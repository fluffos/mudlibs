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
    "north" : ROOMS(royal_baths3),
    "west" : ROOMS(royal_baths1),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(naked_lady) : random(7) + 3,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
  reset() ;
}
