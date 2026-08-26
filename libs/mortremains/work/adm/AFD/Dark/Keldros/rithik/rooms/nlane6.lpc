#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);

  set("short", "a creepy narrow lane.");
  
set("long", @ENDLONG
The area surrounding you is quite gloomy.  The
tall cedar trees shadow you, blocking nearly all light
the sky would bestow.  The ground here is a little rocky
making it somewhat difficult to travel.
ENDLONG
);

  set("item_desc", ([
    "trees" : "The cedar trees look very old, by their size,\nperhaps centuries..\n",
    "ground" : "The ground has many tiny, sharp pebbles..\n",
   
   ]) );
   
  set("smell", ([
    "default" : "The maintains a damp smell, perhaps from such little light it\nreceives.\n",
]) );
  
  set("exits", ([
    "south" :  ROOMS(nlane5.c),
    "north" : ROOMS(nlane7.c),  
  ]) );
  ::create();  
}
