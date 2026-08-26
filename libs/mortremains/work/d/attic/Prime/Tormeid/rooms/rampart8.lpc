// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

object guard ;

void create() {
    seteuid(getuid());
    set("short", "On the ramparts.") ;
    set("long", @ENDLONG
You are on the ramparts of the castle wall.
ENDLONG
    );
    set_outside("Light") ;
    set("exits", ([
      "south" : ROOMS(rampart7),
      "north" : ROOMS(nwtower2),
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
    ]) );
    ::create();
}

void reset() {
    if (!guard) {
	guard=clone_object(MON(wander_guard)) ;
	guard->move(TO) ;
    }
}
