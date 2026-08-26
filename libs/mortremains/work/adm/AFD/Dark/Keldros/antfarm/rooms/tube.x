#include "../defs.h"
inherit ROOM; 

void init(){
  if((int)TP->query("stat/dexterity") < random(10)){
    TP->command("go down");
 }
}
  

void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "in a narrow rock tube.");
set("long", @ENDLONG
This is a narrow rock tube.  It's very rough on both sides.
The walls are covered in a thin layer of water.  Steam
wafts from all sides around you, making your flesh crawl
with goosebumps.  Your footing is quite unsteady from
the near vertical of the tube.
ENDLONG
   );

  set("item_desc", ([
  "walls" : "They are rough, probably carved from the steam that continuously\nrises from below.\n",
    "cave" : "This cave appears to have been built by humanoid creatures.\n",
    "steam" : "Steam rises from the hole that continues down\n",
    "water" : "It's water that has collected on the walls.\n",
    "goosebumps" : "They are big, this steam is quite creepy!\n",
   ]) );
   set("search_desc", ([
     "wall" : "You find a wall.\n",

   ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air.\n",
    "wall"  : "Smells like wet dirt.\n",
    "air"  : "The dank smell of water is quite pronounced here.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear nothing but the steam rising from beneathe you.\n",
    
  ]) );
  set("objects", ([
    MON(frog) : random(2),
      
]) );
 

