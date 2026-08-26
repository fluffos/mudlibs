#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
reset();
set("short", "Antechamber to the Chapel of Ulaa.");
     set ("long",
"This small room sports a few small chairs for\n"+
"people waiting to speak with the priests. On the\n"+
"walls is a large mural of a forested mountain.\n");
     set ("exits", ([
"east" : Oerth+"/rooms/oldlane3",
     ]) );
}
