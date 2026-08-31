#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 2);
    set_short("beach path");
    set_long("The beach path intersects here with the cliffs.  A small "
    "winding path seems to lead up the cliffs, but it isn't certain if it "
    "is natural or artificial.  The cliffs themselves glow with a color "
    "that seems almost magical and unnatural, and the shadows of the cliffs "
    "on the beach seem to dance with a life of their own."
      );
    set_listen("default", "The waves crash gently on the beach.");
    set_smell("default", "The air smells like the ocean.");
    set_exits( ([ "south" : UNAROOM"entrance1",
                  "up" : UNAROOM"path3" ]) );
    set_items(
        (["shadows" : "The shadows dancing on the beach almost seem alive.",
          "sand" : "The sand seems to be made of tiny iridescent crystals.",
          "cliffs" : "The cliffs seem to be made of the same rock as the sand, "
            "imparting a glowing, eerie shimmer."]) );
}
