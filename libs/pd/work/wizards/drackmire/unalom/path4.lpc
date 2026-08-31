#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 2);
    set_short("beach path");
    set_long("The path turns into a small clearing at the top of the cliffs "
             "with a small field replacing the generally rocky terrain of the "
             "area.  The beach can be seen below from here, with its unusual "
             "colors glistening in the light.  The path leads down the cliffs "
             "towards the beach and further north toward a wooded area."
      );
    set_listen("default", "The wind howls.");
    set_smell("default", "Smells of the ocean fill the air.");
    set_exits( ([ "northeast" : UNAROOM"path5",
                  "down" : UNAROOM"path3"]) );
    set_items(
        (["beach" : "The beach looks absolutely brilliant.",
          "path" : "The path turns into a small clearing here."] 
) );
}
