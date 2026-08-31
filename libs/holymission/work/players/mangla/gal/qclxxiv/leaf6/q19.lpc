#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object hag, monster1, monster2, monster3;

extra_reset(arg) { 
	PLACE_IN_ROOM(hag, LEAF+"hag");
	PLACE_IN_ROOM(monster1, LEAF+"viper");
	PLACE_IN_ROOM(monster2, LEAF+"viper");
	if (arg) return;
	items = ({ 
				"heaps","Heaps of bones, some viper bones, most human bones",
				"bones","Some viper bones, most human bones",
				"heap","A heap of bones, some viper bones, most human bones",
			});
}

FOUR_EXIT( LEAF+"q27","northeast",
			LEAF+"q22","west",
			LEAF+"q20","southwest",
			LEAF+"q18","south",
       	 "The Hag's home",
"Here the horrible hag has made her home. She seems to collect bones, as\n"
+"there are heaps of them all around. From the south some light shines in.\n"
+"Sinister sounds come from the west. Wouldn't you go home now?\n"
, 1)

