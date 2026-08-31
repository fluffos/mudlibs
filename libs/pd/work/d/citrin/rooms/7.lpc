//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("a forest");
    set_long("The path seems to disappear from the shadows of "
      "the trees overhead.  Almost no light enters through the "
      "branches of the tall trees.  What can be seen of the path "
      "is covered with leaves and twigs.");
    set_items(([
	"leaves":"The leaves have fallen from the overhead trees.",
	"twigs":"The twigs make crackling sounds when stepped on.",
	({"tree", "trees"}):"The trees grow tall above the ground and "
	"prevent sunlight from entering.\n",
      ]));
    set_exits(([
	"southeast":ROOMS"8",
	"north":ROOMS"5",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

