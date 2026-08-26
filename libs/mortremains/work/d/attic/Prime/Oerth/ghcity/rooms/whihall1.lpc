#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
reset();
set("short", "A well lit hallway.");
     set ("long",
"This is a hallway leading to the rooms.\n");
     set ("exits", ([
"doors" : Oerth+"/rooms/whitehorseinn",
"north" : Oerth+"/rooms/whiroom1",
"south" : Oerth+"/rooms/whiroom2",
     ]) );
}
