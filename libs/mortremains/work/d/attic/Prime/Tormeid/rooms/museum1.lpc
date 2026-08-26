// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large museum.");
  set("long", @ENDLONG
You stand in a large museum dedicated to the history of Tormeid.
Large pictures depict great battles and there are many statues
of warriors from another time period.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "east" : ROOMS(bnhall3),
    "west" : ROOMS(museum2),
  ]) );
  set("item_desc", ([
 "pictures" : "All the pictures depict battles you do not recognize.\n",
  "statues" : "All the statues resemble great warriors, but none that you recognize.\n",
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
