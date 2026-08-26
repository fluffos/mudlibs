// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The Queen's Bedroom.");
  set("long", @ENDLONG
You are standing in the Queen's bedroom.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(rliving3),
  ]) );
  create_door("north", "south", "An ornate gold door.",
  "open", "royal_key", 24) ;
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(queen) : 1,
  MON(liw) : random(4) + 2,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
