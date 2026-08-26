#include "../defs.h"

inherit ROOM; 
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "On a narrow staircase.");
  
set("long", @ENDLONG
This is a narrow staircase leading to the second floor
of the Town Hall.  You can smell a thick smoke in the air,
apparently coming from the floor above you.
ENDLONG
);

  set("item_desc", ([ 
      "smoke" : "It's a thick, grey smoke.\n",
      "stairs" : "The stairs are narrow and made of thick pine.\n",
]) );  
set("smell", ([
    "default" : "The smoke smells like a very rare tobacco.\n", 
  ]) );
  set("exits", ([
     "up" :  ROOMS(hallway),
     "west" : ROOMS(thall),
     ]) );
  ::create();  
}