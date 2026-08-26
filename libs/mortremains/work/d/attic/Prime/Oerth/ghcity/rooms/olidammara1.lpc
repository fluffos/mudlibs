#include <mudlib.h>
#include "oerth.h"

inherit ROOM;
void create() {
     ::create();
          set ("light", 1) ;
seteuid(getuid());
reset();
set("short", "Antechamber to the Chapel of Olidammara.");
     set ("long",
"This small room is bare, save for a small couch\n"+
"that people use if they are kept waiting.\n");
     set ("exits", ([
"west" : Oerth+"/rooms/proc4",
     ]) );
}
