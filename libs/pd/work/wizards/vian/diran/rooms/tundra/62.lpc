#include <std.h>
#include <diran.h>

inherit ROOMS"tundra/zone";

void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
set_long("The icy tundra hopelessly continues in many different directions. A frosty skeleton is propped up against a rock, perhaps it was just too cold for him.  There is a strange bush to the southeast.");
    set_short( "a snowy tundra" );
set_exits(([ "north" : ROOMS"tundra/63",
"southeast" : ROOMS"tundra/hidden",
"west" : ROOMS"tundra/61",]));
add_invis_exit("southeast");
    set_items( ([

]) );
    set_smell("default",  "The dry arctic wind carries little scent.");
    set_listen("default", "The sound of animals and humanoids fighting can be heard throughout the tundra.");

set_items(desc_items());


}
