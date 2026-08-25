#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("no castle", 1);
    set_short( "the southern end of West Road");
    set_long( 
"West Road is the main residential road that runs through Praxis. "
"One or two more houses lie on either side of the road, until "
"it comes to a dead end south of here at Boc La Road. The small "
"huts lining the road are rather run down and unattractive. You "
"can hear noises coming from inside of them, as the inhabitants "
"carry on with their lives.");
    set_items(
	(["road" : "West Road, which marks the westernmost end of Praxis.",
	  "huts" : "They are small peasant huts.",
	  "hut" : "It has a thatch roofing, and is not really extravagant."
	  ]) );
    set_exits( 
	      (["north" : "/domains/Praxis/west_road2",
		"south" : "/domains/Praxis/w_boc_la3"]) );
}

