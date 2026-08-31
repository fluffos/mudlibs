#include <lca.h>
#include <std.h>
#undef GLOBALMSG 

inherit VAULT;

int rope;

void create() {
    ::create();
    set_name("the clock tower");
    set_short("somewhere deep in an abandoned city");
    set_day_long("The room seems bright from the sunlight "
      "entering the clear ceiling.  The floors creak from the "
      "weight they bear of the clock's machinery.  However "
      "the clock no longer works.  There is a rope hanging "
      "from the ceiling");
    set_day_long("The room is dark and lonely.  The floors "
      "creak from the "
      "weight they bear of the clock's machinery.  However "
      "the clock no longer works.  There is a rope hanging "
      "from the ceiling");
    set_exits(([ 
        "east":PRESENT"t4",
      ]));
    set_door("door", ROOMS"tower/4", "east", "old steel key");
    set_open("door", 0);
    set_locked("door", 1);
    set_items(([
      ]));
    set_properties(([ "light":2, "night light":1, "city":1 ]));
}

void reset() { ::reset(); rope=0; }

void init() {
    ::init();
    add_action("pul", "pull");
}

int pul(string str) {
    if(!str || str != "rope") return notify_fail("Pull what?\n");
    if(rope) return notify_fail("It has already been pulled.\n");
#ifdef GLOBALMSG
    message("info", "The church bells of Mursol rings throughout the realms.", 
      users(), ({this_player()}) );
#else
    message("info", "The church bells of Mursol rings throughout the realms.", 
      this_player() );
#endif
    "/d/lca/daemon"->ring();
    return 1;
}

