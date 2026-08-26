#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);

  set("short", "the end of a creepy narrow lane.");
  
set("long", @ENDLONG
The area surrounding you is quite gloomy.  The
tall cedar trees shadow you, blocking nearly all light
the sky would bestow.  The ground here is a little rocky
making it somewhat difficult to travel.  The lane stops
at a set of dark, rusted, large iron gates that stand open
like the lid of a coffin at wake.  Some lettering can be seen
above the top of the gates.
ENDLONG
);

  set("item_desc", ([
    "trees" : "The cedar trees look very old, by their size,\nperhaps centuries..\n",
    "ground" : "The ground has many tiny, sharp pebbles..\n",
    "gates" : "The gates stand nearly twelve feet tall, and are attached to a\nrought iron fence surrounding what appears to be a cemetary.\n",
    "lettering" : "It reads: \"Thy loved ones come home to us at The Happy People cemetary.\"\n",
   ]) );
   
  set("smell", ([
    "default" : "The maintains a damp smell, perhaps from such little light it\nreceives.\n",
]) );
  
  set("exits", ([
    "south" :  ROOMS(nlane6.c),
    "north" : ROOMS(cm.c),  
  ]) );
  ::create();  
}
