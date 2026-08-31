#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 2);
    set_short("beach path");
    set_long("The path here seems very slightly used.  A small amount "
      "of brush and rocks have been pushed to the sides, but it looks "
      "as though no one has used this path in ages.  Just north of here "
      "the path runs into the iridescent cliffs that tower above the beach. "
      );
    set_listen("default", "The waves crash gently on the beach.");
    set_smell("default", "The air smells like the ocean.");
    set_exits( ([ "north" : UNAROOM"path2",
                  "southeast" : UNAROOM"beach" ]) );
    set_items(
        (["shadows" : "The shadows dancing on the beach almost seem alive.",
          "sand" : "The sand seems to be made of tiny iridescent crystals.",
          "cliffs" : "The cliffs seem to be made of the same rock as the sand, "
            "imparting a glowing, eerie shimmer."]) );
}
