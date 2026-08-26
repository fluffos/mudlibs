// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The royal living quarters.");
  set("long", @ENDLONG
You stand in the southeast corner of an enormous, plush room that serves
as the royal living quarters.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(rliving2),
    "south" : ROOMS(kingroom1),
    "west" : ROOMS(rliving3),
  ]) );
  create_door("south", "north", 
"An extremely beautiful gold door with the Royal Crest emblazoned on it.",
  "locked", "king_key", 24 ) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "west" : "$N moves towards the west side of the room.",
    "north" : "$N moves towards the north side of the room.",
  ]) );
  ::create();
}
