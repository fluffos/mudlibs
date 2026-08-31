#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object rat1, vulture1, vulture2, skunk1, nettle;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	PLACE_IN_ROOM(rat1, LEAF+"bigrat");
	PLACE_IN_ROOM(vulture1, LEAF+"qvulture");
	PLACE_IN_ROOM(vulture2, LEAF+"vulture");
	PLACE_IN_ROOM(skunk1, LEAF+"skunk");
	FRESH_IN_ROOM(nettle, LEAF+"nettle");
	if (arg) return;
	items = ({ 
			"path","The dirty remainders of what once may have been a path",
			"track","The dirty remainders of what once may have been a path",
			"filth","The filthiest of all filths has been gathered here",
			});
}

TWO_EXIT( 
			LEAF+"q5","east",
			LEAF+"q10","southeast",
       	 "A dingy, dark, filth-covered track ends here in heaps of filth",
"A dingy, dark, filth-covered track ends here in heaps of filth.\n"+
"The filth almost seems to live, in fact most of it probably does....\n"+
"You have never seen so much filth together anywhere else.\n" , 0)

