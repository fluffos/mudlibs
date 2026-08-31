#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("mountain",1);
    set_short("Nogard path");
    set_day_long(
      "The bottom of a small hill, the mud is more solid "
      "then it looks.  Small clusters of grass breaks up "
      "the brown scenery.  The hill heading north looks a "
      "little slick going, but enough small debris should "
      "provide enough traction.  Going south however, the "
      "mud begins to thicken. "
    );
    set_night_long(
      "Need to set a night long, finish descripts  "
      
    );
    set_items(([
        "boulders" : "Something from above have pushed them "
                  "over, but someone went through and pushed "
                  "them away from the path.",
        "mountain" : "You don't know where these mountains are "
                     "located, but you know that you are very "
                     "high, maybe even near the top of the "
                     "tallest mountain.",
        "clouds" : "They float by the ledge.",
         "path"   : "On either side of the pathway, two "
                    "large piles of rocks sits.  The "
                    "pathway is very rocky, and there is no "
                    "signs of life.",
        "moon"   : "The walls of the path are so smooth, that "
                   "the moon beam bounces around, creating "
                   "more light.",
        "walls"  : "Large boulders lean up against the wall.",
        "wall"   : "Large boulders lean up against the wall.",
        "pathway" : "On either side of the pathway, two "
                    "large piles of rocks sits.  The "
                    "pathway is very rocky, and there is no "
                    "signs of life.",
    ]));
    set_smell("default", "A fresh crisp cold air fills your lungs.");
    set_exits( ([
"north" : BLACK "b43",
"south" : BLACK "b41",
    ]) );
}
