#include "/players/qclxxiv/myroom.h"  
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object fungus, wig1, wig2, wig3, flea1;
object obj_1, obj_2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	FRESH_IN_ROOM(fungus, LEAF+"fungus");
	PLACE_IN_ROOM(flea1, LEAF+"flea");
	PLACE_IN_ROOM(wig1, LEAF+"earwig");
	PLACE_IN_ROOM(wig2, LEAF+"earwig");
	PLACE_IN_ROOM(wig3, LEAF+"earwig");
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf6/q4","shackle","players/qclxxiv/leaf6/inshackle1","south","dirty","inshackle","This is a smudgy dark door.\n",1,1,1)
	obj_1->set_invisible(1);
	items = ({ 
				"path","The dirty remainders of what once has been a path",
				"track","The dirty remainders of what once has been a path",
				"lock", "A dirty lock",
				"shackle","A dingy dark shackle with a dirty dark door",
			});
}

THREE_EXIT( LEAF+"q5","west",
			LEAF+"q3","east",
			LEAF+"q8","southeast",
       	 "A dingy, dark track",
"A dingy, dark shackle alongside what once has been a path. It's terribly humid\n"
+"down here and also rather cold. You start to shiver.\n" , 0)

