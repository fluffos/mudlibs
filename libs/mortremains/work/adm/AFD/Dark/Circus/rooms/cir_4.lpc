#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
set("short", "The eastern portion of the circus grounds.");
  
set("long", @ENDLONG
The main clearing that serves as a path through the circus grounds
has moved to the east.  Small tents powder both sides of the path,
making this look more like a battleground than anything else.
A larger tent can be seen to the south.
ENDLONG
);

  set("item_desc", ([
    "tent" : "The tent is filthy with grime.  You see some white smoke rising from
small holes in the top of it.\n",
    "path" : "This path is well-trodden and covered with filthy hay.\n",
 ]) );
  set("exits", ([
    "south" : ROOMS(grub),
    "east" : ROOMS(cir_7),  
    "west" : ROOMS(grounds), 
]) );
  ::create();  
}
