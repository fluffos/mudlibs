#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("no castle", 1);
    set_short( "a dirt highway");
    set_long(
	"You find yourself on a large dirt highway which heads "
	"west out of Praxis. In the distance the Daroq Mountains " 
"rise majestically over the flat plains of the rest of the lands. "
"This area is rather sparse, with just a small smattering of trees. "
"There appears to have been grass here a long time ago, but it has "
"been ruined from the many adventurers that traverse these parts. "
"East leads to West Boc La road and east takes you to the highway ");
 set_items(
	(["highway" : "A highway linking Praxis to the western lands "
	    "of Nightmare.",
({ "trees", "tree" }) : "The trees are very small. This isn't "
"a very good environment for them to grow in.",
	  "village" : "A tiny adventuring village. They have many "
	    "services there.",
	  "mountains" : "The Daroq Mountains are far to the west."
	]) );
    set_exits( 
	      (["west" : "/domains/Praxis/highway2",
		"east" : "/domains/Praxis/w_boc_la3"]) );
}

