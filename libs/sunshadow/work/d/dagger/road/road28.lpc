// Chernobog (3/22/22)
// Dagger Road

#include <std.h>
#include "/d/dagger/road/short.h"
inherit "/d/dagger/yniam/inherit/dagger_road";

void create(){
    ::create();
    set_exits(([
        "northeast" : RPATH "road29",
        "west" : "/d/dagger/tonovi/2path1",
        "south" : RPATH "road27",
        ]));
}

void init(){
    ::init();
    // Calls wandering monster daemon
    RDEMON->startup();
}

