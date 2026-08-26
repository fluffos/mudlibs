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
"This is a well lit hallway on the second floor\n"+
"of the Brass Dragon Inn. It runs north and south.\n");
     set ("exits", ([
"stairs" : Oerth+"/rooms/brassdragoninn",
"north" : Oerth+"/rooms/bdihall2",
"south" : Oerth+"/rooms/bdihall3",
     ]) );
}
