// Chernobog & Titania (2/25/22)
// Wailing Isle - Market Street

#include <std.h>
#include "../defs.h"
inherit INH+"market";

void create(){
    ::create();
    set_exits(([
        "north" : ROOMS"marketsquare",
        "south" : ROOMS"market1",
        ]));
}

void reset(){
    ::reset();
    if(!present("merchant")) new(MON "random_vendor")->move(this_object());
    if(!present("ambiance device")) new(MON"ambiance_market")->move(this_object());
}

