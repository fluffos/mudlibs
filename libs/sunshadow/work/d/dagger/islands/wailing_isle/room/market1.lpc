// Chernobog & Titania (2/25/22)
// Wailing Isle - Market Street

#include <std.h>
#include "../defs.h"
inherit INH+"market";

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"market2",
        "south" : ROOMS"path1",
        ]));
}

void reset(){
    if(!present("ambiance device")) new(MON"ambiance_market")->move(this_object());
}

