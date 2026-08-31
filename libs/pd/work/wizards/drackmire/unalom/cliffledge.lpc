#include <std.h>
#include "unalom.h"
inherit ROOM;

void create() {
    ::create();
    set_short("The ledge of a cliff");
    set_long(
      "The cliff ledge here overlooks the beach and the ocean, "
      "which, given the particular shimmer of the sand from up here "
      "is a breathtaking view.  The rocky cliffs cast shadows on the "
      "ledge which seem to almost watch you, while a few bushes grow "
      "just north of here against the cliff wall."
    );
    set_exits( 
      (["east" : UNAROOM"path3",
        "north" : UNAROOM"dwarfcave"
      ]) );
    set_invis_exits(({"north"}));
    set_pre_exit_functions(({"north"}), ({"do_north"}));

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["cliffs" : "High and majestic, these cliffs seem to be made of something unearthly",
         "shadows" : "The shadows from the cliffs seem to dance in the light, almost "
         "seeming to watch you.",
         "bushes" : "The bushes just north of here grow against the cliff.  They almost "
         "seem to be obscuring something, a cave maybe.",
         "cave" : "There are some bushes here covering the entrance of a cave, you could "
         "certainly push past the bushes."
      ]) );
}
int do_north() {
    write("A thorn sticks you in the side as you push the bushes aside.");
    this_player()->add_hp(-5+random(20));
    return 1;
}
