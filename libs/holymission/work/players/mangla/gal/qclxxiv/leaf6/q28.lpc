#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object must, hyena1;

extra_reset(arg) { 
	FRESH_IN_ROOM(must, LEAF+"must");
	PLACE_IN_ROOM(hyena1, LEAF+"hyena");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking hyena shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( LEAF+"q29","west",
			LEAF+"q12","northeast",
       	 "A dimly lit, stinking passage. Heaps of dirt are all around",
"A dimly lit, stinking passage. Heaps of dirt are all around. Hyena shit is\n"
+"all over the place.\n", 1)

