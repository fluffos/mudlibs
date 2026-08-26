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
"of the Brass Dragon Inn. It runs north and south.\n"+
"There is a door to the east, and to the west.\n");
     set ("exits", ([
"north" : Oerth+"/rooms/bdihall1",
"south" : Oerth+"/rooms/bdihall5",
"west" : Oerth+"/rooms/bdiroom5",
"east" : Oerth+"/rooms/bdiroom6",
     ]) );
}
