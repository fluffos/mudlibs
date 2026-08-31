#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object fungus, hyena1, hyena2;

extra_reset(arg) { 
	FRESH_IN_ROOM(fungus, LEAF+"fungus");
	PLACE_IN_ROOM(hyena1, LEAF+"hyena");
	PLACE_IN_ROOM(hyena2, LEAF+"hyena");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking hyena shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( LEAF+"q30","west",
			LEAF+"q28","east",
       	 "A dimly lit, stinking passage. Heaps of dirt are all around",
"A dimly lit, stinking passage. Heaps of dirt are all around. Hyena shit is\n"
+"all over the place. The stench gets worse here.\n", 1)

