#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Slerne's House");
    set("long", "This looks to be a temporary abode of a dragon.  There's not much "+
      "furniture anywhere, although there is a big rock against the back wall that "+
      "that emanates heat and looks surprisingly comfortable.  The main zoo is back"+
      " to the south.");
    set_exits( ([ "south" : ROOMS"zoopath10",
	"east" : ROOMS + "dragonhouse2" ]) );
    set_items(
      (["rock" : "This is more of a rock shelf.  It grows out of the wall and covers"+
	"even a little bit of the corner.  It is spacious and looks to be able to "+
	"function as either a place to lounge or even sleep on.",
	"shelf" : "It's contoured in several places, and rather flat.",
	"wall" : "It has a large rock shelf up against it."
      ]) );
}
void reset() {
    ::reset();
    if(!present("slerne")) {
	new(MOB"slerne")->move(this_object());
    }
}
