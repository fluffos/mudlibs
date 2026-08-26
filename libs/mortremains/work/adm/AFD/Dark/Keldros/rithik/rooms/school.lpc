#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "Front door of a school house.");
  
set("long", @ENDLONG
This is a large hallway within the schoolhouse.  You see doors lining the
north and south walls.  There are names engraved in plaques beside each door.
To the west the hallway continues to a very large door.
ENDLONG
);

  set("item_desc", ([
    "plaques" : "Each plaque is engraved with a name.\n",
    "names" : "They are names of teachers that teach in the school.\n",
    "door" : "It's a large door marked \"Principle's office\".\n",
]) );
   
  

  
  set("exits", ([
    "exit" : ROOMS(corner),
    "west" : ROOMS(office.c),
    "mr.ades" : ROOMS(ades.c),
    "mrs.krauss" : ROOMS(krauss.c),
    "mrs.racine" : ROOMS(racine),
    "mr.lyman" : ROOMS(lyman),
 ]) );
  ::create();  
}
