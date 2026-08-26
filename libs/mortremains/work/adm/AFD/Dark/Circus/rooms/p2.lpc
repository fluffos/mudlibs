#include "../defs.h"

inherit ROOM;   
object trainer;
void create() {
  seteuid(getuid());
  set("author", "Waxer");  
  set("light", 1);
set("short", "the Animal Trainer's room.");
  
set("long", @ENDLONG
This room is quite pungent in odor and is filthy.  All kinds
of different forms of feces line the floor and walls.  Along
the walls you also see straps and metal buckles, supposedly
for training large animals.
ENDLONG
);

  set("item_desc", ([
    "straps" : "Thes straps could be used to constrict a very large animal.\n",
    "buckles" : "These are used for the straps that accompany them.\n",
    "feces" : "This is the excrement of unknown creatures.\n",
 ]) );
  set("exits", ([
    "west" : ROOMS(ptent),
]) );
  ::create();  
}
void reset(){
  if(!trainer){
     trainer = clone_object(MON(trainer));
     trainer->move(TO);
  }
::reset();
}