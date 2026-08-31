#include <std.h>
#include "unalom.h"

inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set_property("light", 2);
    set_short("a path");
    set_long("The path here broadens from a rocky trail to almost "
    "a well-worn road as it leads into a dense forest.  The rocks "
    "lining the path shimmer in the light with an unnatural, almost "
    "magical glow.  Some forest animals scurry back and forth from "
    "cliff rocks to the forest, searching for food washed up on the "
    "beach."  
      );
   set_listen("default", "The sounds of forest animals emanate from the forest.");
    set_smell("default", "Smells of the ocean fill the air.");
    set_exits( ([ "north" : UNAROOM"path6",
                  "southwest" : UNAROOM"path4"]) );
    set_items(
        ([ ({ "animals", "animal" }) : "Occasionally an animal will "
        "scurry out of the forest and down to the beach, looking for food.",
          "path" : "The path widens as it enters the forest."] 
) );
}
