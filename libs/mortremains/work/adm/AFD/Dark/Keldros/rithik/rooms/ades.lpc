

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "Mr. Ades' Classroom.");
  
set("long", @ENDLONG
Mr. Ades' classrom is adorned with drawings of the stars.  The room is also
covered in paint among other things, apparently tossed on the walls by his students.
Each desk has its own unique color, since each desk changes color as the children
have tossed paint at thier leisure.
ENDLONG
);

  set("item_desc", ([
    
    "paint" : "It's a thick, water-based paint.\n",
    "desk" : "This is a wooden desk, covered in paint.\n",
     "drawings" : "It appears Mr. Ades had a love for astronomy.\n",
    "stars" : "These are drawn stars of of Keldrosian night sky.\n",
    "walls" : "The walls are covered in paint, thrown by children possibly.\n",
    "color" : "The colors range from green to dark red.\n",

]) );
   set("objects", ([
    MON(mrades) : 1,
    MON(child1) : 1,
    MON(child2) : 1,
    MON(child3) : 1,
    MON(child4) : 1,
    
  
]) );
  
  set("exits", ([
    "south" : ROOMS(school),
   
 

 ]) );
  ::create();  
}
