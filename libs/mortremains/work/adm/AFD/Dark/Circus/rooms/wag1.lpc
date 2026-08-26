#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  
  set("light", 0);
  set("short", "Inside a dark wagon.");
  
set("long", @ENDLONG
The air is very dank here.  From inside, the roof looks much higher than
it did from the outside.  The walls of the wagon are layered with shelves
laiden with straps, chains, spikes and all other sorts of generic building
equipment.  You can see a very large stool sitting towards the front of the
wagon.
ENDLONG
);

  set("item_desc", ([
    "equipment" : "It appears that this equipment has been used recently.\n",
    "stool" : "This stool is intended for a very heavy humanoid to rest on.\n",
     "roof" : "There is enough heighth for a tall humanoid to walk comfotably.\n",
 ]) );
   
  set("smell", ([
    "default" : "You smell dust and old leather.\n", 
    "equipment" : "It smells of fresh dirt and oil.\n",
    "stool" : "You pick up the faint odor of a beer fart.\n",
]) );

set("objects", ([
       MON(cyc) : 1,
]) );
  set("exits", ([
    "out" : ROOMS(cir_1),  
]) );
  ::create();  
}
