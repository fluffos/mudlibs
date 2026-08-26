

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "Mrs. Racine's Classroom.");
  
set("long", @ENDLONG
Mrs. Racine's classroom has crimson walls and a black
and white checkered floor.  There is very little light
in this room.  The walls are decorated with posters
with single words on them.
ENDLONG
);

  set("item_desc", ([
    
    "poster" : "The posters appear to be spelling lessons for the dwarven
language.\n",
    "posters" : "The posters appear to be spelling lessons for the dwarven
language.\n",
     "walls" : "These walls are a dark red.\n",
    "words" : "They are words from the dwarven language\n",

]) );
   set("objects", ([
    MON(mrsracine) : 1,
    MON(rchild1) : 1,
    MON(rchild2) : 1,
    MON(rchild3) : 1,
]) );
  
  set("exits", ([
    "north" : ROOMS(school),
 ]) );
  ::create();  
}
