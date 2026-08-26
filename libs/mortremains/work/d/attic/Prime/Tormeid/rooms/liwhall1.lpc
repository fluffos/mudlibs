// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A hallway.");
  set("long", @ENDLONG
You stand in a plain hallway between the Ladies-In-Waiting Room and
the Royal Chambers.
ENDLONG
  );
  set("light", 1) ;
  set("exits", ([
    "east" : ROOMS(liwhall2),
    "south" : ROOMS(liwroom1),
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
