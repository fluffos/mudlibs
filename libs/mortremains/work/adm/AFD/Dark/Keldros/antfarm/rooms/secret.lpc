
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);

  set("short", "in an ancient study.");
  
set("long", @ENDLONG
This appears to once have been an ancient study.  It has now
succumbed to the filth and grime that lines the walls and
covers the floors.  It appears no one has been down here in quite
some time.
ENDLONG
   );
  set("smell", ([
    "default" : "Dust and other horrendous odors assault you.\n", 
]) );

  set("item_desc", ([
   "filth" : "Feces and blood, among other things make an icky grime that covers nearly
everything here.",
   "grime" : "Feces and blood, among other things make an icky grime that covers nearly
everything here.",
   "walls" : "The walls once held hundreds of ancient tomes, now they have been reduced to
shreds.\n",
   "floor" : "It's a stonework floor, covered in filth.\n",
]));
  set("listen", ([
   "default" : "You hear a furnace burning above you.\n",
 ]) );
  set("objects", ([

]) );

  set("exits", ([
    "up" :  ROOMS(end),
]) );
  ::create();  
}
