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
"of the Brass Dragon Inn. It only runs south.\n"+
"There is a door to the east, and to the west.\n");
     set ("exits", ([
"south" : Oerth+"/rooms/bdihall2",
"west" : Oerth+"/rooms/bdiroom3",
"east" : Oerth+"/rooms/bdiroom4",
     ]) );
}
