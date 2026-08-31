//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The path is very muddy.  The overfill of the lake runs through "
      "small area causing it mostly to be nothing but swamp.  The "
      "only type of vegetation that grows here is that of a small, "
      "poisoness red fern.");
    set_items(([
      ]));
    set_exits(([
	"northwest":ROOMS"16",
	"southwest":ROOMS"19",
      ]));
    set_pre_exit_functions( ({"northwest", "southwest"}), ({"go_northwest", "go_southwest"}) );
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if(!present("fern"))
	new(OBJ"fern")->move(this_object());
}

int go_northwest() {
    write("You jump off of the catwalk to the soft mud below.\n");
    return 1;
}

int go_southwest() {
    if(random(2)) 
	write("The boards of the catwalk creak.\n");
    return 1;
}

