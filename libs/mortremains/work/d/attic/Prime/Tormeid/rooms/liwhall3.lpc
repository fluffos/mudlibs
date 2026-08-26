// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

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
  "west" : ROOMS(liwhall2),
    "east" : ROOMS(rliving3),
  ]) );
  create_door("east", "west", "A solid gold door."
    , "locked",
  "royal_key",
  24) ;
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
