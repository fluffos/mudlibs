#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object felon, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(felon, LEAF+"felon");
	PLACE_IN_ROOM(monster1, LEAF+"skunk");
	PLACE_IN_ROOM(monster2, LEAF+"skunk");
	if (arg) return;
	items = ({ 
				"heaps","Heaps of bones, some human bones, most monk's bones",
				"bones","Some human bones, most monk's bones",
				"heap","A heap of bones, some human bones, most monk's bones",
			});
}

FOUR_EXIT( LEAF+"q31","southeast",
			LEAF+"q23","west",
			LEAF+"q20","northwest",
			LEAF+"q18","north",
       	 "Fiendish felon's place",
"The fiendish felon's place. You feel mostly unwelcome here. It's near dark.\n"
+"Bones are all around, stacked to heaps. From the north some light shines in.\n"
+"This place is utterly depressing. What are you seeking here?\n"
, 1)

