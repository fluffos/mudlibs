// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "Ladies-in-Waiting Bedroom.");
  set("long", @ENDLONG
This is the bedroom of all the Ladies-In-Waiting for the Queen.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(bnhall2),
    "north" : ROOMS(liwhall1),
  ]) );
  create_door("west", "east", "A beautiful mahogany door.",
  "locked", "servant_key", 23) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
    MON(liw) : random(10) ,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
