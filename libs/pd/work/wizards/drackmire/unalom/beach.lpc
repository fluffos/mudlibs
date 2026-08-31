#include <std.h>
#include "unalom.h"

inherit DOCKS;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 2);
    set_short("Unalom Beach");
    set_long("This beach is mostly deserted, except for a few low growing "
      "bushes growing in the sand.  The sand here is a brilliant color, "
      "almost iridescent, and seems to cause the shadows on beach to "
      "have a life of their own.  A trail leads away from the beach towards "
      "the cliffs, which have their own iridescent glimmer.");
    set_listen("default", "The waves crash gently on the beach.");
    set_smell("default", "The air smells like the ocean.");
    set_exits( ([ "northwest" : UNAROOM"entrance1" ]) );
    set_items(
        (["shadows" : "The shadows dancing on the beach almost seem alive.",
          "sand" : "The sand seems to be made of tiny iridescent crystals.",
          "cliffs" : "The cliffs seem to be made of the same rock as the sand, "
            "imparting a glowing, eerie shimmer."]) );
    set_letter("z");
}
