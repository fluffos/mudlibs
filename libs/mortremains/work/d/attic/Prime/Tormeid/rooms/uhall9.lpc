// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "west":ROOMS(uhall8),
  "east" : ROOMS(uhall10),
  "south" : ROOMS(bedroom11),
  "north" : ROOMS(bedroom12),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
