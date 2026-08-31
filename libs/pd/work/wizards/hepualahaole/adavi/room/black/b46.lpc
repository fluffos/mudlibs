#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("mountain",1);
    set_short("Nogard path");
    set_day_long(
      "On a ledge over-hanging the world's tallest mountains.  "
      "Clouds float by underneath, covering up the existence "
      "of a world beneath.  A faint and narrow path is guided "
      "upwards by two mountain sides, smoothly carved by "
      "skilled hands.  However, the view is cut short, when the "
      "path veers to the east."
    );
    set_night_long(
      "The brillent moon beam, dances on the smoothly carved "
      "walls that are on either side of the pathway.  Looking "
      "behind, scattered clouds glisten as they float by "
      "underneath."
    );
    set_items(([
        "ledge" : "You peer over the ledge and you realize that "
                  "it overhangs and all there is are clouds "
                  "floating by underneath.",
        "mountain" : "You don't know where these mountains are "
                     "located, but you know that you are very "
                     "high, maybe even near the top of the "
                     "tallest mountain.",
        "clouds" : "They float by underneath, too far to jump "
                   "down.",
        "world"  : "The clouds block your view of the world.",
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
"north" : BLACK "b45",
    ]) );
}
