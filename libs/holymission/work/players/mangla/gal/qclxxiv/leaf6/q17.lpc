#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object timmy, cockroach1, cockroach2, cockroach3;

extra_reset(arg) { 
	PLACE_IN_ROOM(timmy, LEAF+"timmy");
	PLACE_IN_ROOM(cockroach1, LEAF+"cockroach");
	PLACE_IN_ROOM(cockroach2, LEAF+"bigrat");
	PLACE_IN_ROOM(cockroach3, LEAF+"sowbug");
	if (arg) return;
	items = ({ 
				"shit","Heaps of stinking rat shit",
				"dirt","It's the dirtiest dirt you've ever seen",
				"heaps","Heaps of the dirtiest dirt you've ever seen",
				"heap","A heap of the dirtiest dirt you've ever seen"
			});
}

TWO_EXIT( 
			LEAF+"q10","east",
			LEAF+"q18","west",
       	 "A stinking, dimly lit room. Heaps of dirt are all around",
"A stinking, dimly lit room. Heaps of dirt are all around. Rat shit is\n"
+"all over the place. The stench is sickening here. In fact this room is\n"
+"just a small inner hall in the rotten leaf 6, but little Timmy lives here\n"
+"amongst his friends. Apart from all the dirt, there's not much in the room.\n"
+"From the west a sinister light shines in.\n"
, 1)

