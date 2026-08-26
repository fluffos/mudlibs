#include "../defs.h"
inherit ROOM;   
void create() {
seteuid(getuid()); 
set("author", "Waxer");  
set("light", 1);
set("short", "Inside Rithik Town Hall.");
set("long", @ENDLONG
This is the Rithik Town Hall.  The smell of dust and paper stands stale here.
The walls are lined with drawings of apparently important individuals to
Rithik.  A small desk rests against the south wall covered with piles
of organized papers.
ENDLONG
);
set("item_desc", ([
    "desk" : "This appears to be a receptionist's desk.\n",
    "drawings" : "Judging from the pictures, the former mayors of this town
were quite wealthy.\n",
    "papers" : "Thousands of pieces of paper line the desk, neatly piled, all bearing the
same title:  Appointments Coming up.\n",
    "walls" : "There are drawings lining the walls.\n",
]) );
set("smell", ([
    "default" : "You smell dust and paper rotting in stasis.\n", 
  ]) );

set("objects", ([ MON(sec) : 1, ]));
set("exits", ([
     "west" : ROOMS(lane2), 
     "east" : ROOMS(stairs),
 ]) );
set("pre_exit_func", ([
     "east" : "guarded",
  ]) );
  ::create();
}

int guarded() {
  if (present("secillia", TO)) {
    write("Secillia says: \"You don't have an appointment today.\"\n");
   return 1;
  }
  return 0;
}



