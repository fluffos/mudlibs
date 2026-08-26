// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand at the end of a large hallway on the second floor of the castle.
A large statue of a woman holding a child is here, near the east door.
ENDLONG
  );
  set("item_desc", ([
  "statue" : "The statue is a beautiful portayal of a mother and child.\n",
  ]) ) ;
  set("light", 1) ;
  set("exits", ([
  "east" : ROOMS(rampart32),
    "west" : ROOMS(uhall14.c),
  ]) ) ;
  create_door("east", "west", "A solid iron door with a slit.",
   "closed", "guard_captain", 27 ) ;
  ::create();
}
