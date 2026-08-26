// The ant tunnels.

#include "../defs.h"

inherit ROOM;

#define NUM_PROTS 3

object ant, queen;

void create() {
    int i;

    ::create();
    seteuid(getuid());
    set("short", "In a tunnel.");
    set("long", "You are in one of the endless tunnels in the "+
      "gigantic anthill.  All the\ntunnels seem to look alike, and "+
      "you feel as though you might get lost if\nyou aren't careful.\n");
    set("smell", "All you can smell is the reek of ammonia.\n");
    set("exits", ([
      "south" : ROOMS(ants29),
    ]) ) ;

    // Clone the queen, and the mack warrior ants that 
    // protect her.

    queen = clone_object(MON(queen.c));
    if (queen) queen->move(TO);
    queen->set("protectors", ({}) );

    for (i=0; i<=NUM_PROTS; i++) {
	int lvl;
	ant = clone_object(MON(worker.c));
	if (!ant) break;
	ant->set_level( ant->query_level() + 2 );
	ant->delete("wandering");
	ant->set("protecting", ({ queen }) );
	queen->add("protectors", ({ ant }) );
    }    
}

/* EOF */
