//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The air is dry and cool.  The ground is soft, almost muddy.  "
      "Grey puffs of smoke lightly float into the air originating somewhere "
      "to the south.  The path is well defined and is very clean.  The only "
      "obstruction in the path is a small tree starting to grow in the "
      "middle of the path.");
    set_exits(([
	"northeast":ROOMS"47",
	"southeast":ROOMS"25",
      ]));
    set_items((["ground":"The ground is soft, almost muddy.",
	"smoke":"Its grey smoke...  Duh!",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if(!present("tree"))
	new(OBJ"tree")->move(this_object());
}

