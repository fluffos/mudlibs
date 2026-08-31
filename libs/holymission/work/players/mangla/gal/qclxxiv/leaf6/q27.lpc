#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object vortex, cockroach1, cockroach2, cockroach3;

extra_reset(arg) { 
	PLACE_IN_ROOM(vortex, LEAF+"vortex");
	PLACE_IN_ROOM(cockroach1, LEAF+"cockroach");
	PLACE_IN_ROOM(cockroach2, LEAF+"cockroach");
	PLACE_IN_ROOM(cockroach3, LEAF+"cockroach");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking jackal shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( 
			LEAF+"q26","east",
			LEAF+"q19","southwest",
  	 "The end of a stinking, dimly lit alley. Heaps of dirt are all around",
"The end of a stinking, dimly lit alley. Heaps of dirt are all around.\n"
+"Jackal shit is all over the place. The stench is sickening here.\n"
+"Vortex has made his room here, and lives here amongst his akin.\n"
+"From the southwest a sinister light is shines in.\n"
, 1)

