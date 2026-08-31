#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object beast, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(beast, LEAF+"leggobeast");
	PLACE_IN_ROOM(monster1, LEAF+"vulture");
	PLACE_IN_ROOM(monster2, LEAF+"vulture");
	if (arg) return;
	items = ({ 
				"heaps","Heaps of bones, mostly human",
				"bones","All kinds of bones, mostly human",
				"heap","A heap of bones, mostly human",
			});
}

TWO_EXIT( LEAF+"q21","southeast",
			LEAF+"q19","northeast",
       	 "Leggo beast's livingroom",
"Leggo beast's living room. It looks cosy in a way. It is light in here.\n"
+"In the corners there are some heaps, nearly out of sight.\n"
, 1)

