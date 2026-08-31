#include <std.h>
#include <diran.h>

inherit ROOMS"mountainpath/zone";

void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
set_short("a mountain pass");
    set_long( desc_long() );
set_exits(([ "west" : ROOMS"mountainpath/40",
"east" : ROOMS"mountainpath/38",
]));
    set_items( ([

]) );
    set_smell("default",  "The dry arctic wind carries little scent.");
    set_listen("default", "The sound of animals and humanoids fighting can be heard throughout the mountain pass.");

set_items(desc_items());


}
