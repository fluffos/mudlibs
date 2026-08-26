#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "at the battle of Cephrin");
  set("long", @EndDesc
Here, at the edge of the battlefield, the skeletons begin to
thin out.  Very little remains of a road that once flourished here.
The clearing dead ends into a deep wooded area leading northeast
into the Keldrosian range.  A decrepit sign can be seen in the weeds.
EndDesc);

set("item_desc", ([ 
    "battlefield" : "This is the edge of the battlefield, few skeletons remain here.\n",
    "road" : "You are standing on a wide clearing that once was a road.\n",
    "sign" : "It is broken nearly to pieces, and is barely legible.\n",
    "clearing" : ""+query("item_desc/road")+"",
]));

set("exits", ([
     "west" : ROOMS(bat),
]));

::create();
}
void init(){
  add_action("read", "read");
}
int read(string arg){
   if(!arg || arg !="sign") return 0;
write(@EndSign

---------->
cephrin 2dc

(local and king's taxes apply)
EndSign);
return 1;
}