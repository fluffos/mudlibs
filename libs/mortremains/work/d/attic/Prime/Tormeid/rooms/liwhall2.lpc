// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A hallway.");
  set("long", @ENDLONG
You stand in a plain hallway between the Ladies-In-Waiting rooms and
the Royal Chambers.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "east" : ROOMS(liwhall3),
    "west" : ROOMS(liwhall1),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(liw) : random(1) ,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
  reset() ;
}
