#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 2);
    set_short("beach path");
    set_long("As the path ascends up the cliffs, it gets rockier and narrower, "
    "to the point where it may barely be a path at all.  A few boulders to the west "
    "make it possible to get to a ledge there, while the main path keeps ascending "
    "the shimmering cliffs.  The shadows of the cliffs on the path almost seem "
    "to warn you."
      );
    set_listen("default", "The wind howls against the cliffs.");
    set_smell("default", "Spray from the ocean still fills the air.");
    set_exits( ([ "west" : UNAROOM"cliffledge",
                  "up" : UNAROOM"path4",
                  "down" : UNAROOM"path2"]) );
    set_items(
        (["shadows" : "The shadows dancing on the cliff almost seem alive.",
          "cliffs" : "The cliffs seem to be made of the some unearthly rock."]  ) );
}
