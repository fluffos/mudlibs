#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object beast, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(beast, LEAF+"miscreant");
	if (arg) return;
	items = ({ 
				"heaps","Heaps of bones, mostly human",
				"bones","All kinds of bones, mostly human",
				"heap","A heap of bones, mostly human",
			});
}

TWO_EXIT( LEAF+"q24","southwest",
			LEAF+"q19","east",
       	 "Home of the Malicious miscreant",
"Home of the Malicious miscreant. It is scary in here. The stench is sickening.\n"
+"Heaps of bones cover the floor.\n"
, 1)

