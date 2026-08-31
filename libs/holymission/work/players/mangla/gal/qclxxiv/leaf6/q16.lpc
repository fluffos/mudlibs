#include "/players/qclxxiv/myroom.h"  
#include "/players/qclxxiv/door.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object rat1, vulture1, skunk1, skunk2, nettle;
object obj_1, obj_2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	PLACE_IN_ROOM(rat1, LEAF+"bigrat");
	PLACE_IN_ROOM(vulture1, LEAF+"vulture");
	PLACE_IN_ROOM(skunk1, LEAF+"qskunk");
	PLACE_IN_ROOM(skunk2, LEAF+"skunk");
	FRESH_IN_ROOM(nettle, LEAF+"nettle");
	if (arg) return;
	MAKE_DOORS("players/qclxxiv/leaf6/q16","shelter","players/qclxxiv/leaf6/inshelter1","north","musty","inshelter","This is a dingy dark door.\n",1,1,1)
	obj_1->set_invisible(1);
	items = ({ 
			"path","The grubby remainders of what once may have been a path",
			"track","The grubby remainders of what once may have been a path",
			"filth","The filthiest of all filths has been gathered here",
			"trash","Large heaps of trash piled up against a shelter",
			"heaps","Large heaps of trash piled up against a shelter",
			"lock", "A musty lock",
			"shelter","A dark mouldy shelter with a dingy dark door",
			});
}

TWO_EXIT( 
			LEAF+"q15","east",
			LEAF+"q10","northeast",
       	 "A smudgy, dark, filth-covered track ends here in heaps of filth",
"A smudgy, dark, filth-covered track ends here in heaps of filth.\n"+
"The filth almost seems to live, in fact most of it probably does....\n"+
"A dark mouldy shelter is almost covered from sight by heaps of trash.\n"+
"You have never smelled such a filthy stench anywhere else.\n" , 0)

