#include "../defs.h"
inherit ROOM;
inherit DOORS;
int scuffle(int i){
   object mon, mon1;
 mon = present("kurn", TO);
 mon1 = present("mayor", TO);
if(!mon1) return 1;
tell_object(TO, "The man dressed in black pushes the mayor out of the window!\n");
tell_object(TO, "The mayor screams as he plummets to his death!\n");
call_other("/d/Dark/Voltros/rooms/sec", "do_it");
call_other("/d/Dark/Voltros/rooms/mayors", "make_corpse");
mon1->remove();
return i;
}

void create(){
  seteuid(getuid());
  set("light", 1);
set("short", "The Mayor's office.");
set("long", @ENDLONG
This is the office of the Mayor.  A large plush chair sits behind
a rather large desk.  The walls here, like in the secretaries room,
are covered in books.  
ENDLONG
   );
  set("item_desc", ([
  "chair" : "Burn holes are in the seat....\n",
  "desk" : "Large campaign posters are strewn about the desk.\n",
	"walls" : "The walls hold nothing but books...All of them have a
thick layer of dust on them.\n",
   ]) );
set("exits", ([
   "north" :  ROOMS(sec), 
               ]));
create_door("north", "south", "wooden door.",
    "closed", 5);
set("objects", ([
    												MON(mayor) : 1,
                MON(mib) : 1,
                
  ]));
::create();
}
void init(){
  if(!userp(TP))return ;
   call_out("scuffle", 3, 1);
 }