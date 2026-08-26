// Chernobog & Titania (2/25/22)
// Wailing Isle - Beach

#include <std.h>
#include "../defs.h"
inherit INH+"beach";

void create(){
    ::create();
    set_exits(([
        "northeast" : ROOMS"beach4",
        "south" : ROOMS"beach2",
        ]));
}

void reset(){
    if(!present("rocky pedestal")) new(OBJ"shrine")->move(this_object());
}

