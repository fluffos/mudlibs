#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object must, beetle1, beetle2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	FRESH_IN_ROOM(must, LEAF+"must");
	PLACE_IN_ROOM(beetle1, LEAF+"dungbeetle");
	PLACE_IN_ROOM(beetle2, LEAF+"dungbeetle");
	if (arg) return;
	items = ({ 
				"path","It's in very bad condition",
				"dung","It's the kind that dung-beetles like"
			});
}

TWO_EXIT( LEAF+"q3","west",
			LEAF+"q1","southeast",
       	 "A dingy, dimly lit path",
"A dingy, dimly lit path. Everything is musty here. Dung lies around.\n", 1)

