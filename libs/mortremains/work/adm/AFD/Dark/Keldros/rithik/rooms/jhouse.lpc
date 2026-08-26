

#include "../defs.h"

inherit ROOM;   
object dick;
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "A small jailhouse.");
set("long", @ENDLONG
You are standing in what appears to be a jailhouse telling from the wall
of bars on the eastern wall.  There is a small desk resting here with a
rickety chair behind it.
ENDLONG
);
  set("item_desc", ([
       "bars" : "These bars are to contain prisoners within.  The cell looks like
it hasn't been used in quite sometime.\n",
       "desk" : "The desk looks like it is used by the town sherrif.\n",
        "chair" : "The chair is nearly worn out from continuous use.\n",
       "wall" : "This is a wall of bars, to prevent the escape of whoever is behind it.\n",
]) );
  set("smell", ([ 
         "default" : "Dust and sweat are the prominent odors here.\n",
]) );
  set("exits", ([
    "west" : ROOMS(lane),
 ]) );
  ::create();  
}

void reset(){
  if(!dick){ dick = clone_object(MON(sherrif)); dick->move(TO); }
::reset();
}