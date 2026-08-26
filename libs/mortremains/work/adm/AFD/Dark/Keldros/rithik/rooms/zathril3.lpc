#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);

  set("short", "Zathril meets a worn path.");
set("long", @ENDLONG
A well worn path leads to the north here.  Chimney plumes can be spotted
in that direction.  Zathril continues westward and eastward.  A rotten 
wooden sign nailed to a nearby tree.
ENDLONG
);

  set("item_desc", ([ 
      "sign" : ">----------Rithik-----------<
  Population 320
\n",
      "tree" : "there is a old broken sign attached to it.\n",
       "sky" : "There is no godly reason why the sky would be so red.\n",
 ]) );
  set("exits", ([
     "north" : ROOMS(main),
     "west" : ROOMS(hole.c),
     "east" : ROOMS(zathril2), 
     ]) );
  ::create();  
}
