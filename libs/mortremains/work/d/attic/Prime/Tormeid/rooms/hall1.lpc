// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a magnificient hallway within the castle.  To the north,
you can see a quaint little coatroom, and a stairway lies to the south.
The hallway continues to the east.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "west" : ROOMS(courtyard1),
   "north" : ROOMS(coatroom),
  "south" : ROOMS(stairwell1),
   "east" : ROOMS(hall2),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
   MON(guard2) : 2,
 ]) );
  create_door("west", "east", "It's a solid oak door", "closed",
  "-", 30) ;
  ::create();
}
