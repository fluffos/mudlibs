#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object serpent, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(serpent, LEAF+"serpent");
	PLACE_IN_ROOM(monster1, LEAF+"bigrat");
	PLACE_IN_ROOM(monster2, LEAF+"bigrat");
	if (arg) return;
	items = ({ 
				"heaps","Heaps of bones, some rat bones, others human",
				"bones","Some rat bones, others human",
				"heap","A heap of bones, some rat bones, others human",
			});
}

THREE_EXIT( LEAF+"q17","east",
			LEAF+"q19","north",
			LEAF+"q21","south",
       	 "The serpent's charter",
"The serpent's charter, where the slime serpent uses to live.\n"
+"Heaps of bones are all over the place. Some are rat bones, some are human.\n"
+"The stinking atmosphere is spoiled by the serpent's stench.\n"
, 1)

