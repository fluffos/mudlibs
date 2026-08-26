// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The courtyard.");
  set("long", @ENDLONG
You stand in the castle's courtyard.  The stables are to the south, and
a door leads east.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(main1),
    "south" : ROOMS(stable),
    "east" : ROOMS(hall1),
  ]) );
  set("item_desc", ([
  ]) );
  create_door("east", "west", "It's a solid oak door", "closed", "-", 34) ;
  ::create();
}
