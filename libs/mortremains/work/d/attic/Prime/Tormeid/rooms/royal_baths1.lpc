// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The royal baths.");
  set("long", @ENDLONG
You are in the royal baths.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "south" : ROOMS(rliving2),
    "north" : ROOMS(royal_baths2),
    "east" : ROOMS(royal_baths4),
  ]) );
  create_door("south", "north", "An ornate golden door.",
   "closed", "royal_key", 24) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(naked_lady) : random(4) + 4,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
