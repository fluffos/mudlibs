#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object darkmoon, rat1, rat2, rat3;

extra_reset(arg) { 
	PLACE_IN_ROOM(darkmoon, LEAF+"darkmoon");
	PLACE_IN_ROOM(rat1, LEAF+"bigrat");
	PLACE_IN_ROOM(rat2, LEAF+"bigrat");
	PLACE_IN_ROOM(rat3, LEAF+"bigrat");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking hyena shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( 
			LEAF+"q30","east",
			LEAF+"q21","northwest",
"The end of a dimly lit, stinking passage. Heaps of dirt are all around",
"The end of a dimly lit, stinking passage. Heaps of dirt are all around. \n"
+"Hyena shit is all over the place. The stench is sickening here.\n"
+"Some creep named Darkmoon seems to live here amongst his ilk.\n"
+"From the northwest a sinister light shines in.\n"
, 1)

