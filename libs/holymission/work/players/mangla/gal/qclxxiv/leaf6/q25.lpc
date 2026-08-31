#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object fungus, jackal1, jackal2;

extra_reset(arg) { 
	FRESH_IN_ROOM(fungus, LEAF+"fungus");
	PLACE_IN_ROOM(jackal1, LEAF+"jackal");
	PLACE_IN_ROOM(jackal2, LEAF+"jackal");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking jackal shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( LEAF+"q26","west",
			LEAF+"q3","southeast",
       	 "A stinking, dimly lit alley. Heaps of dirt are all around",
"A stinking, dimly lit alley. Heaps of dirt are all around. Jackal shit is\n"
+"all over the place.\n", 1)

