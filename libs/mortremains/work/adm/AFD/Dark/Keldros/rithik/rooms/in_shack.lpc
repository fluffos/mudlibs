#include "../defs.h"

inherit ROOM;   
inherit DOORS;
void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);

  set("short", "inside a cruddy shack.");
  
set("long", @ENDLONG
You stand inside a broken-down shack that once used to
be a nice home.  All that remains of the furnishings is
a wood-burning stove and a feather cot that lies in a corner.
ENDLONG
);

set("objects", ([ MON(c_man.c) : 1, ]));
  set("item_desc", ([
    "stove" : "This is an ancient wood-burning stove.\n",
    "cot" : "It looks like a filthy sleeping place.\n",
    "boards" : "The boards look quite old and dry.",
    "windows" : "What windows?  The glass litters the ground infront of the house.\n",
    "lantern" : "The lantern is lit.\n",
    "glass" : "The glass is in splinters on the ground.\n",
   ]) );
   
  set("smell", ([
    "default" : "The maintains a damp smell, perhaps from such little light it\nreceives.\n",
    "lantern" : "You smell fresh oil burning in the lanterm.\n",
]) );

  set("exits", ([
    "west" :  ROOMS(shack),  
  ]) );
create_door("west", "east", "The door is rotten and could be easily smashed down", "closed", "", 2);
  ::create();  
}
