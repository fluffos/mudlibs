#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object stinkhorn, hyena1, hyena2, rat1, rat2;

extra_reset(arg) { 
	FRESH_IN_ROOM(stinkhorn, LEAF+"stinkhorn");
	PLACE_IN_ROOM(hyena1, LEAF+"hyena");
	PLACE_IN_ROOM(hyena2, LEAF+"hyena");
	PLACE_IN_ROOM(rat1, LEAF+"bigrat");
	PLACE_IN_ROOM(rat2, LEAF+"bigrat");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking hyena shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( LEAF+"q31","west",
			LEAF+"q29","east",
       	 "A dimly lit, stinking passage. Heaps of dirt are all around",
"A dimly lit, stinking passage. Heaps of dirt are all around. Hyena shit is\n"
+"all over the place. The stench gets more terrible every step to the west.\n"
, 1)

