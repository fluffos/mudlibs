#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object beast, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(beast, LEAF+"fright");
	if (arg) return;
	items = ({ 
				"heaps","Large heaps of bones, mostly human",
				"bones","All kinds of bones, mostly human",
				"heap","A large heap of bones, mostly human",
			});
}

TWO_EXIT( LEAF+"q24","northwest",
			LEAF+"q21","east",
       	 "Foul fright's hiding place",
"Foul fright's hiding place. It's cold and close to dark in here.\n"
+"Bones are piled up to large heaps.\n"
, 1)

