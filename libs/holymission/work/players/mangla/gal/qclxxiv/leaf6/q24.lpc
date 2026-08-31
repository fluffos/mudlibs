#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object beast, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(beast, LEAF+"basilisk");
	if (arg) return;
	items = ({ 
				"heaps","Heaps of bones, most of them are human bones",
				"bones","All kinds of bones, mostly human bones",
				"heap","A heap of bones, most of them are human bones",
		"walls","Just normal walls with heaps of bones piled up against them",
			});
}

TWO_EXIT( LEAF+"q23","southeast",
			LEAF+"q22","northeast",
       	 "Banefule basilisk's barn",
"Barn of the baneful basilisk. It is near dark here, you can hardly see a\n"
+"thing. Heaps of bones cover the floor and are piled up against the walls.\n"
, 1)

