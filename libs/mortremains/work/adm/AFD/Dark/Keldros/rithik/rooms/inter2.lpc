

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "The road continues.");
  
set("long", @ENDLONG
The road continues through Rithik.  The trees become thinner, and you notice
more activity.  You see a small building to the west that everyone seems to be
ignoring.  To the east sounds of song call to you, it appears to be a pub.
North on the path, it looks as though the road turns to the east.
ENDLONG
);

  set("item_desc", ([
    "building" : "A sign above the door proclaims it to be the \"Rithik Town Library\"\n",
    "pub" : "It looks like a nice place to hang out and get something to drink.\n",
    "road" : "This road is well trodden, suggesting regular use.\n",
   ]) );
  set("exits", ([
    
    "west" : ROOMS(lib.c),
    "south" : ROOMS(inter.c),
    "north" : ROOMS(corner.c),
    "east" : ROOMS(pub.c),
    
  ]) );
  ::create();  
}
