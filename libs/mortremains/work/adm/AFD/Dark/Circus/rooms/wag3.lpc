#include "../defs.h"

inherit ROOM;   
object gypsy;
void create() {
  seteuid(getuid());   

  set("author", "Waxer");  
  set("light", 1);
  set("short", "Desmeralda's Wagon.");
  
set("long", @ENDLONG
The wagon tilts towards the front of the vehicle, forcing
a lot of the materials within to coagulate there.  Varied
pieces of clothing and jewelry litter the floor and the walls.
A small crystal ball is mounted to a small table in the center
of the room.
ENDLONG
);

  set("item_desc", ([
      "clothing" : "Clothing litters the entire wagon, colorful, but poorly made.\n",
      "jewelry" : "This jewelry is worthless.\n",
      "ball" : "A simple crystal ball used by some for scrying purposes.\n",
      "table" : "It's made of thin wood, very cheaply constructed.\n",
 ]) );
   
  set("smell", ([
    "default" : "You smell decaying cotton and other fibers.\n", 
    "lamp" : "It smells like it is leaking more oil than it's using.\n",
    "stool" : "You pick up the faint odor of a beer fart.\n",
]) );
  set("objects", ([ MON(des.c) : 1, ]));
  set("exits", ([
    "out" : ROOMS(cir_6.c),  
]) );
  ::create();  
}


