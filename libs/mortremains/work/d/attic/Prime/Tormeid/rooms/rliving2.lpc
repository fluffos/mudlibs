// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The royal living quarters.");
  set("long", @ENDLONG
You stand in the northeast corner of an enormous, plush room that serves as
the royal living quarters.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(royal_baths1),
    "east" : ROOMS(rlibrary1),
    "south" : ROOMS(rliving4),
    "west" : ROOMS(rliving1),
  ]) );
  create_door("north", "south", "An ornate golden door.", "closed",
    "royal_key", 24) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "west" : "$N moves towards the west side of the room.",
    "south" : "$N moves towards the south side of the room.",
  ]) );
  ::create();
}
