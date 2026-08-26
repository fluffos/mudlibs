// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The stables.");
  set("long", @ENDLONG
Bales of hay line the western wall and the smell of manure and sweat
fills the air.  Horse stalls line the eastern wall, each filled with
hay.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(courtyard1),
  ]) );
  set("item_desc", ([
  "bales" : "Bales of hay are stacked up against the wall.\n",
  "hay" : "Hay is scattered all about the floor, along with manure.\n",
  "manure" : "It looks as gross as it smells.\n",
  "stalls" : "All of the stalls seem to be empty, except for the hay.\n",
  ]) );
  set("search_desc", ([
  "manure" : "You can't bring yourself to do it.\n",
   "hay" : "You'd rather not, considering the manure mixed in with it.\n",
  ]) );
  set("smell", ([
  "default" : "You smell manure and sweat.\n",
  "stalls" : "The smell of manure is very strong in there.\n",
  "manure" : "It smells like a potent fertilizer.\n",
  ]) );
  set("objects", ([
  "boy" : MON(stable_boy), 
  ]) );
  ::create();
}
