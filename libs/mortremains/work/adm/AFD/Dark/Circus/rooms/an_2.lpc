

#include "../defs.h"

inherit ROOM;   
object hans;
void create() {
  seteuid(getuid());   
 set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
  set("short", "Near some large cages.");
set("long", @ENDLONG
You see cages lining the east and portion of the path.  Hay covers the
ground, mixed with mud and apparent animal feces.  The red sky casts an eerie
glow up the large cages, giving them an ethereal quality.  The smell of wet 
animal fur turns your stomach.
ENDLONG
);

  set("item_desc", ([
    "cages" : "The cages are made of red wood and iron, they are fashioned to contain
animals of non-domesticated animals.\n",
    "hay" : "Hay has been used to thicken the mud for easier passage, and to feed
some of the horses.\n",
    "feces" : "This is the excrement of many different animals.\n",
]) );
  
  set("exits", ([
   "north" : ROOMS(an_1),
    "east" : ROOMS(cage3),  
    "west" : ROOMS(cage4), 
]) );
  ::create();  
}
void reset()
{
  if(!hans){
      hans=clone_object(MON(hans.c));
      hans->move(TO);
}
::reset();
}