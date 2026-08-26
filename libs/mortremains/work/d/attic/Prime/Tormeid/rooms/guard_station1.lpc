// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"


int reset;
inherit ROOM;
inherit DOORS;

void create() {
  seteuid(getuid());
  set("short", "A guard station.");
  set("long", @ENDLONG
A small table with two chairs on either side lie in the center of the room,
and a small oil lantern hangs directly above it, providing light.  A windy
little iron-wrought staircase works its way up towards the upper levels of
the wall.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(guard_storage),
   "south" : ROOMS(main1),
  "up" : ROOMS(guard_station2),
  ]) );
  set("exit_msg", ([
   "up" : "$N ascends the stairs.",
  ]) ) ;
  set("item_desc", ([
  "table" : "It's completely bare except for some notch marks.\n",
  "notches" : "It looks as if somenoe started carving the table out of boredom.\n",
  "chairs" :"They are facing the table.\n", 
  "lantern" : "It hangs from the ceiling, providing light.\n",
  "staircase" :"It spirals up to the upper levels.\n", 
  ]) );
  set("objects", ([
  MON(guard2) : random(4),
  MON(guard4) : random(3),
  MON(guard3) : 1 
 ]) );
  create_door("north", "south", "It's a stong iron door.", "locked",
  "guard_captain", 45) ;
  ::create();
}

void reset() {
  if (!reset) {
     reset = 1;
     ::reset() ;
   return ;
  }
  ::reset() ;
  find_object_or_load(ROOMS(guard_storage))->reset() ;
  set("doors/north/status", "locked") ;
  message("door",
     "The lock in the north door clicks loudly.\n",
    TO ) ;
  find_object_or_load(ROOMS(guard_storage))->set("doors/south/status", "locked") ;
  message("door",
    "The lock in the south door clicks loudly.\n",
   find_object_or_load(ROOMS(guard_storage))) ;
}

