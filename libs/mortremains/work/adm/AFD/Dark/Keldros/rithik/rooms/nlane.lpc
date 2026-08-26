

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "the narrow, northern lane.");
  
set("long", @ENDLONG
This is a narrow lane divides a section of homes into
two rows.  The homes appear small, but quite neat and
tidy.  The path leads to the north and south.
ENDLONG
);

  set("item_desc", ([
    "homes" : "The homes are well constructed and kept up.\n",
    "rows" : "The rows are the result of well-planned contruction\neach house is directly north or south from its neighbor.\n",
    "lane" : "This is a narrow lane that is well traveled.\n",
   ]) );
   
  set("smell", ([
    "default" : "You smell cedar.  A slight breeze carries a smoky smell
from the south.\n",
]) );
  
  set("exits", ([
    "south" :  ROOMS(corner),
    "north" : ROOMS(nlane2.c),  
  ]) );
  ::create();  
}
