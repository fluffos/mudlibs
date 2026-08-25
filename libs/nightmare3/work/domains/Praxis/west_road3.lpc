#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("enter", "enter");
}

void create() {
    ::create();
    set_property("light", 2);
    set_short( "the north end of West Road");
    set_long(
"West Road comes to an abrupt end as it is engulfed by the forest "
"to the north. A huge ancient willow tree provides shelter to "
"this entire section of the road. At its massive roots you can "
"see a whole leading down into the depths of the earth. Boc La Road "
"lies far south of here.");
    set_items(
	(["tree" : "It must be older than Praxis itself.",
	  "hole" : "You might even be able to enter the tree.",
	  "road" : "This end of the road is shaded by the huge "
	    "tree of mysterious origins.",
	  "foo" : "You're daft.",
	  "bar" : "Had to check that too, eh?"]) );
    set_exits( 
	      (["south" : "/domains/Praxis/west_road2"]) );
}

int enter(string str) {
    if(!str) {
	notify_fail("Enter what?\n");
	return 0;
    }
    if(str != "hole" && str != "tree") {
	notify_fail("You can't do that here.\n");
	return 0;
    }
    this_player()->move_player("/domains/Praxis/mage_join", "into the tree");
    return 1;
}

