

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set("short", "The home of a hunter.");
  
set("long", @ENDLONG
This home smells of fresh-baked burkhberry pie.  Pots and pans
are numerous strewn about the kitchen.  An oven rests in the
center of the room, emanating heat and cooking whatever is inside.
ENDLONG
);
  set("item_desc", ([
   "pots" : "These are deep pots meant for brewing and boiling.\n",
   "pans" : "Most of these pans are pie-shaped, for great baking.\n",
   "oven" : "This is a pot-belly oven meant for heating and cooking.\n",
   "kitchen" : "The kitchen is a mess, but smells wonderfull!\n",
   "room" : "Try \"look\", you are standing in the middle of it.\n",
]) );
  set("smell", ([ 
         "oven" : "It smells of baking burkhberry pie, YUM!\n",
         "defalut" : "The smell of burkhberry pie is wonderful here.\n",
]) );
   set("objects", ([
    MON(woman) : 1,
]) );
  
  set("exits", ([
    "north" : ROOMS(street.c),
 ]) );
  ::create();  
}
