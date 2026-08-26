#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "A small Church.");
  
set("long", @ENDLONG
This is the Rithik Town Library.  This is a very large building with books lining
each shelf.  Dust covers nearly everything, suggesting that this building is never
used.  The shelves are crafted from oak wood.  Before you is an enormous desk,
it is apparent that whoever oversees the library would use this desk.
ENDLONG
);

  set("item_desc", ([
    "desk" : "This is a very old desk it lacks a chair and is devoid of drawers.\n",
    "dust" : "This dust is caused from years of stasis.\n",
    "shelves" : "They support hundreds of pounds of books.\n",
    "wood" : "The wood is quite sturdy.\n",
   ]) );
   
  set("smell", ([
    "default" : "You smell old books and dust.\n", ]) );

  set("objects", ([
    MON(libr) : 1,
  ]) );
  set("exits", ([ "east" : ROOMS(inter2), ]) );

  ::create();  
}
