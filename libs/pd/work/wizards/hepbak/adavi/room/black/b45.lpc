#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("mountain",1);
    set_short("Nogard path");
    set_day_long(
      "Looking south, a narrow ledge planks over the clouds.  "
      "The path to the east leads deeper in between the "
      "mountain tops.  Walls on either side was masterfully "
      "chiseled out to a sheer finish. "
    );
    set_night_long(
      "The brillent moon beam, dances on the smoothly carved "
      "walls that are on either side of the pathway.  Looking "
      "south, scattered clouds glisten as they float by. "
    );
    set_items(([
        "ledge" : "A large rock piercing the sky."
                  "it overhangs and all there is are clouds "
                  "floating by underneath.",
        "mountain" : "You don't know where these mountains are "
                     "located, but you know that you are very "
                     "high, maybe even near the top of the "
                     "tallest mountain.",
        "clouds" : "They float by the ledge.",
         "path"   : "On either side of the path, two mountains "
                   "are smoothly carved.  The path is very "
                   "rocky, and there is no signs of life.",
        "moon"   : "The walls of the path are so smooth, that "
                   "the moon beam bounces around, creating "
                   "more light.",
        "walls"  : "You don't know who carved these walls so "
                   "smoothly.",
        "wall"   : "You don't know who carved this wall so "
                   "smoothly.",
        "pathway" : "On either side of the pathway, two "
                    "mountains are smoothly carved.  The "
                    "pathway is very rocky, and there is no "
                    "signs of life.",
    ]));
    set_smell("default", "A fresh crisp cold air fills your lungs.");
    set_exits( ([
"east" : BLACK "b44",
"south" : BLACK "b46",
    ]) );
}
