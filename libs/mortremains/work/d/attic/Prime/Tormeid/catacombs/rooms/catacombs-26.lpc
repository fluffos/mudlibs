// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "In the catacombs.");
  set("long", "You stand in the musty catacombs beneath the castle.\nAll of the passages down here look alike, and you have a feeling it wouldn't\nbe hard to get lost down here.\n");
  set("light", 1) ;
  set("objects", ([
  "zombie" : MON(zombie.c),
   "goblin" : MON(goblin),
  ]) ) ;
  set("exits", ([
    "east" : ROOMS(catacombs-34),
    "north" : ROOMS(catacombs-7),
    "west" : ROOMS(catacombs-2),
  ]) ) ;
  ::create();
  reset();
}
/* EOF */
