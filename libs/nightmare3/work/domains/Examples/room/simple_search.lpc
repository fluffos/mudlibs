#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_short("a darkened wood");
    set_long(
      "A darkened wood encroaches upon you, making you feel helpless "
      "and insignificant in the face of its vastness.  Giant trees "
      "which make up the woods tower up so high that you would never know "
      "that there was ever a sky if you had not once been beyond the "
      "woods' edge.  There is no path anywhere."
    );
    set_items( ([ 
      ({ "wood", "woods", "forest" }) : "A dark and vast forest about which "
        "you have heard many unpleasant \"myths\".",
      "trees" : "They tower all about you.  Some are higher than any you "
        "have ever seen anywhere else.  Most in fact are.",
      "tree" : "This tree is made of some unknown bark.  It rises way up "
        "into what you are sure is the sky somewhere.",
      "path" : "You wish!"
    ]));
    set_exits( ([ "north" : "/domains/Examples/room/search" ]));
    set_search("woods", "You notice only a tiny break to the north.");
}
