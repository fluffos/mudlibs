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
  "east" : ROOMS(uhall2),
  "south" : ROOMS(warroom),
  "north" : ROOMS(guard_station2),
  "west" : ROOMS(rampart1),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
   MON(guard2) : 2,
 ]) );
 create_door("west", "east", "A strong wooden door.", "closed", "--", 22) ;
 create_door("north", "south", "A strong wooden door.", "open", "--", 22) ;
  ::create();
}


