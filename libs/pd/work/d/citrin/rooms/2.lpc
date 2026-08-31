//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;


void create() {
    ::create();
    set_name("dirt path");
    set_short("an old dirt path");
    set_long("The path leads to the east and west.  In the distance to the "
      "east is a large forest.  Small puffs of white smoke rise "
      "from the center of the woods.  The entrance can be seen "
      "near the path but is off to the south of the path by a "
      "couple of feet.  The tall grass on the side of the path "
      "virtually makes it imposible to cross.  Dust rises "
      "from the breeze running though here.");
    set_items(([
	"path":"The path is dusty and leads from the east to west.",
	({"forest","large forest"}):"It is very large and holds a "
	"variety of animals.",
	"smoke":"Puffs of white smoke rise from the canopy from "
	"perhaps a campfire.",
	"entrance":"It doesnt look like you can pass the grass without "

	"it being cut.",
	({"grass","tall grass"}):"It is way to high to cross.",
	"dust":"The dust in the air makes it hard to see.",
      ]));
    set_exits(([
	"east":ROOMS"4",
	"west":ROOMS"1",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

