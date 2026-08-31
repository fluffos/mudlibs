#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
    ::create();
    set_short("In a forest");
    set_long("The Zexorion forest. There are almost no "
      "trees or foilage here. There are no animals. "
      "A deep rumble comes from the south, where smoke rises up. ");
    set_items((["tree" : "A giant tree blocking the road to the south",
	"trees" : "Almost no trees here.",
	({"bushes", "leaves", "grass"}) : "Just foilage on the ground"]));
    set_listen("default", "You hear a deep rumbling from the south");
    set_exits((["northwest" : ROOMS"path4",
	"southwest" : ROOMS"path6"]));
}

void reset() {
    ::reset();
    if(!present("elf"))
	new(MOB"felf")->move(this_object());
}
