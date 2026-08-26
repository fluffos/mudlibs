// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The royal library.");
  set("long", @ENDLONG
You stand in the royal library.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(rliving2) ,
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(liw) : random(2) ,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
