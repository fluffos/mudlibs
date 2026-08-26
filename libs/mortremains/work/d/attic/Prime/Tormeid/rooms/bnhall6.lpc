// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "east" : ROOMS(rhall1),
  "west" : ROOMS(groom1),
  "south" : ROOMS(bnhall5),
  ]) );
  create_door("east", "west",
  "A beautiful mahogany door bearing the Royal Crest.",
   "locked", "royal_key", 24) ;
  create_door("west", "east", "A beautiful mahogany door leading to the game rooms.", "closed", "--", 23) ;
  set("item_desc", ([
  ]) );
  set("objects", ([
   MON(door_guard2) : 2 ,
 ]) );
  ::create();
}

