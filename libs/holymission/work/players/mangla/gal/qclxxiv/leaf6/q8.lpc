#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object bug1, bug2, louse1, lantarn;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	PLACE_IN_ROOM(louse1, LEAF+"louse");
	PLACE_IN_ROOM(bug1, LEAF+"sowbug");
	PLACE_IN_ROOM(bug2, LEAF+"sowbug");
	FRESH_IN_ROOM(lantarn, HOME+"lanthorn");
	if (arg) return;
	items = ({ 
				"paths", "Two badly kept paths are to the north and south",
				"path", "You can hardly call that a path",
				"bottom","It's covered with stinking moulds",
				"moulds","They are covering the entire stinking bottom here",
			});
}

FOUR_EXIT( 
			LEAF+"q4","northwest",
			LEAF+"q9","west",
			LEAF+"q14","southwest",
			LEAF+"q7","east",
       	 "A stinking place in between some paths",
"A stinking place in between some paths. The place is dimly lit. The bottom\n"+
"is covered with moulds. You can hardly see a thing here.\n", 1)

