#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Waxer");  
  set("light", 0);
  set("short", "inside a small house.");
set("long", @ENDLONG
The house is sparsely furnished, with only a small table
with a single chair and a bed roll in the southwest corner.
It smells of rot and decay, leading you to believe nothing
living would enjoy living here, but stranger things have happened.
ENDLONG
);
set("item_desc", ([
                   "table" : "The table was well-made, but it is covered with rubbish.\n",
                   "chair" : "The chair would be a nice foot stool, for a dwarf.\n",
                   "bed room" : "This appears to be the only sleeping quarters availible in the house.\n",
]));
set("objects", ([ MON(kings) : 1, ]));
set("exits", ([
  "south" : ROOMS(cm_house),
]) );
::create();
}