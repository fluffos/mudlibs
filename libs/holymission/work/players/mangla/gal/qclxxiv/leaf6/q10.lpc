#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object viper1, viper2, viper3, cr1, cr2, stinkhorn;

extra_reset(arg) { 
	PLACE_IN_ROOM(viper1, LEAF+"qviper");
	PLACE_IN_ROOM(viper2, LEAF+"viper");
	PLACE_IN_ROOM(viper3, LEAF+"viper");
	PLACE_IN_ROOM(cr1, LEAF+"cockroach");
	PLACE_IN_ROOM(cr2, LEAF+"cockroach");
	FRESH_IN_ROOM(stinkhorn, LEAF+"stinkhorn");
	if (arg) return;
	items = ({ 
				"bottom","It's covered with stinking moulds",
				"wall","It's covered with stinking moulds",
				"trashcan", "It is not what is seems to be...maybe enter it?",
				"moulds","They are covering the entire stinking bottom here",
			});
}

THREE_EXIT( 
			LEAF+"q6","northwest",
			LEAF+"q16","southwest",
			LEAF+"q9","east",
       	 "A damp, dark place with a filthy smell",
"A damp, dark place with a filthy smell. You feel quite uncomfortable here.\n"+
"A dirty, rusty trashcan stands against a grubby wall to the west.\n"+
"Some, sort of edible, stinkhorns can usually be found around here.\n", 0)

init() {
	::init();
	add_action("trashcan","enter");
}

trashcan(str) {
    if (str=="trashcan") { 
    	call_other(this_player(), "move_player", "via trashcan#"+LEAF+"q17" );
    	return 1;
	}
	return 0;  
}

