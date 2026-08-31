#include <std.h>
#include <blackserver.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("mountain",1);
    set_short("Nogard path");
    set_day_long(
      "Boulders are pushed high against the walls as the "
      "path curves and veers into a slight downhill "
      "direction.  At the end of the hill, it is then "
      "swallowed up in shallow mud that stretches between "
      "the two mountains.  Large grooves, etched in by "
      "streams of rain water, create patterns along the "
      "embedded rocks in the walls."
    );
    set_night_long(
      "Need to set a night long, finish descripts and "
      "put in a climb command in here."
    );
    set_items(([
        "boulders" : "Something from above have pushed them "
                  "over, but someone went through and pushed "
                  "them away from the path.",
        "mountain" : "You don't know where these mountains are "
                     "located, but you know that you 
re very "
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
"south" : BLACK "b42",
"west" : BLACK "b44",
    ]) );
}
void init() 
{
    ::init();
    add_action("climbfunc", "climb");
}
int climbfunc(str)
{
    if(str == "rock")
    {
        write("You start your ascent up the cliff."); 
        message("room message", this_player()->query_cap_name()+" climbs up the
cliff.", this_object(), this_player()); 
this_player()->set_paralyzed(16);
        call_out("climb2", 5); 
        return 1;
    }
}
int climb2()
{
    write("Rocks cuts into your fingers as you pull yourself up.");
        call_out("climb3", 5); 
    return 1;
}
int climb3()
{
    write("Sweat pours down your face as you struggle to get up onto the
ledge.");
        call_out("climb4", 5); 
    return 1;
}
int climb4()
{
    write("Some rocks scatter to the ground as you hoist yourself up on the
ledge.");
        this_player()->move_player(BLACK "b47", "climbs up the cliff."); 
    return 1;
}
