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
				"wall","It's covered with stinking moulds",
				"trashcan", "It is not what is seems to be...maybe enter it?",
				"dung","It's the kind that dung-beetles like"
			});
}

TWO_EXIT( LEAF+"q13","west",
			LEAF+"q11","northeast",
       	 "A smudgy, dimly lit path",
"A smudgy, dimly lit path. Everything is musty here. Dung lies around.\n"
+"A dirty, rusty trashcan stands against a grubby wall to the south.\n"
, 1)

init() {
	::init();
	add_action("trashcan","enter");
}

trashcan(str) {
    if (str=="trashcan") { 
    	call_other(this_player(), "move_player", "via trashcan#"+LEAF+"q28" );
    	return 1;
	}
	return 0;  
}

