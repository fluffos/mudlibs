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
"of the Brass dragon Inn. it only runs to the north.\n"+
"There is a door to the east, and to the west.\n");
     set ("exits", ([
"north" : Oerth+"/rooms/bdihall3",
"west" : Oerth+"/rooms/bdiroom7",
"east" : Oerth+"/rooms/bdiroom8",
     ]) );
}
