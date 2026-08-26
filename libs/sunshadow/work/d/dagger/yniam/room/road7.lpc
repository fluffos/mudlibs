// Chernobog (3/15/22)
// Interior Yniam Road

#include <std.h>
#include "../defs.h"
inherit INH"road2";

void create(){
    ::create();
    set_exits(([
        "northwest" : ROOMS"road6",
        "east" : "/d/dagger/road/road20",
        ]));
}

void reset(){
    ::reset();
    
    if(!present("ambiance device")) new(OBJ"ambiance")->move(this_object());
}

