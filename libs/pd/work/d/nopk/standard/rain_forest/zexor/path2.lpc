#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
    ::create();
    set_short("In a forest");
    set_long("The Zexorion forest. There are "
      "trees all around. There are bushes, leaves, and grass "
      "all over the ground.");
    set_listen("default", "You hear birds chirping");
    set_items((["trees" : "Many different trees",
	({"bushes", "leaves", "grass"}) : "Just foilage on the ground"]));
    set_exits((["south" : ROOMS"path3",
	"northeast" : ROOMS"path1"]));
}

void reset() {
    ::reset();
    if(!present("panther")) {
	new(MOB"panther")->move(this_object());
	new(MOB"panther")->move(this_object());
	new(MOB"panther")->move(this_object());
    }
}
