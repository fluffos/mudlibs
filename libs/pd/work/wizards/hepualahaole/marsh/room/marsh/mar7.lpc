#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Mystic Marsh.");
    set_day_long(
      "In a distance, ripples appear in the water.  The water around "
      "here cleared up a little bit.  There seems to be more trees in "
      "this area.  Thick moss hangs from a nearby tree giving it the "
      "look of some beast.  "
    );
    set_night_long(
      "This is the better part of the marsh, the water is more blue "
      "than a drab mud color.  Something strange is going on in "
      "this part of the marsh.  A rolling mist slowly sets in vanishing "
      "everything in sight."
    );
    set_items(([
        "marsh" : "It is the better part of the marsh, not so messy.",
        "trees" : "The trees here looks very lush.",
        "mud" : "It is less muddier here.",
    ]));
    set_smell("default", "It smells like wet soil after a day's rain.");
    set_listen("default", "Sounds of creature slashing in a distance");
    set_exits( ([
"north" : MARSH "mar12",
"south" : MARSH "mar5",
"swim" : MARSH "surface",
    ]) );
    add_invis_exit("swim");
}
void init()
{
 ::init();
 add_action("Fswim", "swim");
}
int Fswim()
{
 write("%^YELLOW%^You swim out to the middle and notice a hole in the water.%^RESET%^");
 return 0;
}
