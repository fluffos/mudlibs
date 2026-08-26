#include "../defs.h"

inherit ROOM;   
inherit DOORS;
void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);

  set("short", "outside a broken-down shack.");
  
set("long", @ENDLONG
Before you lies a broken down shack, the boards that once
made this a fine home now have betrayed it to age and decay.
The windows that once shielded the occupants, lay shattered
on the ground outside.  A small lantern hangs from the doorframe.
ENDLONG
);

  set("item_desc", ([
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
    "east" :  ROOMS(in_shack),
    "west" :  ROOMS(nlane5),  
  ]) );
create_door("east", "west", "The door is rotten and could be easily smashed down", "closed", "", 2);
  ::create();  
}
