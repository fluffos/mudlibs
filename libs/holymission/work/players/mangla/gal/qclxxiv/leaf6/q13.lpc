#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object mould, beetle1, flea1, flea2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	FRESH_IN_ROOM(mould, LEAF+"mould");
	PLACE_IN_ROOM(beetle1, LEAF+"dungbeetle");
	PLACE_IN_ROOM(flea1, LEAF+"flea");
	PLACE_IN_ROOM(flea2, LEAF+"flea");
	if (arg) return;
	items = ({ 
				"path","It's hardly a path anymore actually",
			});
}

THREE_EXIT( LEAF+"q14","west",
			LEAF+"q12","east",
			LEAF+"q7","northeast",
       	 "A smudgy, dimly lit path",
"A smudgy, dimly lit path. Everything is mouldy here. You can hardly see a\n"
+"thing here. The smell of vomit is all around.\n", 1)

