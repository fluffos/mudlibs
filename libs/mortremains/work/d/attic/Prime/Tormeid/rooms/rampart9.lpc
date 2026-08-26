// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"


inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.");
  set("long", @ENDLONG
You are on the ramparts of the castle wall.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "west" : ROOMS(nwtower2),
    "east" : ROOMS(rampart10),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}


