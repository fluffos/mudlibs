// Chernobog & Titania (3/4/22)
// Wailing Isle - Wharf

#include <std.h>
#include "../defs.h"
inherit INH+"wharf";

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"wharf3",
        "south" : ROOMS"wharf1",
        ]));
}

void reset(){
    if(!present("harbormaster")) new(MON"brookes")->move(this_object());
}

