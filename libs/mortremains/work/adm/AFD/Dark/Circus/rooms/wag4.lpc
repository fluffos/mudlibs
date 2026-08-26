#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  
  set("light", 1);
  set("short", "an unatural room.");
  
set("long", @ENDLONG
The air hangs still here.  The room is completely barren
except for a strange site indeed.

A pool of green swirling liquid dominates the floor.  No
sound can be detected emiting from it.  Only the eerie
glow and the swirling motion can you detect of it.

ENDLONG
);

  set("item_desc", ([
    "pool" : "This pool perhaps might not be liquid, but perhaps a gateway to a plane
other than this....\n",
]) );
   
  set("smell", ([
    "default" : "You smell dust and old leather.\n", 
    "equipment" : "It smells of fresh dirt and oil.\n",
    "stool" : "You pick up the faint odor of a beer fart.\n",
]) );
  set("exits", ([
    "out" : ROOMS(cir_7),  
]) );
  ::create();  
}
void init(){ add_action("jump","jump"); }

//NOTE:  This pool _will_ lead to something cool, but as of 8-14-96, nothing has been //found.

int jump(){
  write("You have too much fear to jump into the pool of swirling matter.\n");
return 1;
}
