#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_smell("default", "A wood smell fills the air.");
    set_listen("default", "Few things can be heard outside of the shelter.");
    set_properties((["light":2, "no attack":1, "no bump":1, "no steal":1, "indoors":1]));
    set_short("Sturdy Shelter");
    set_long(
        "This tiny shelter can hold a few people, protecting them from the "
        "elements or wild creatures.  The walls are composed of thick branches "
        "bound together with sinew from various creatures.  This place feels safe.");
    set_items(
        (["walls" : "The walls are just a bunch of branches tied together.",
          "branches" : "The branches are thick and sturdy.",
          "sinew" : "Looking at the sinew, you realize that it's the internal fibers of a few animals."]) );
}
