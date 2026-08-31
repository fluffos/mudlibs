#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object mildew, grub1, grub2;

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Monsters in this area are non-aggressive as long as the place\n"
		+"is marked as safe. Lots of food can be found here. The monsters\n"
		+"get tougher the further you go to the west.\n";
}
extra_reset(arg) { 
	FRESH_IN_ROOM(mildew, LEAF+"mildew");
	PLACE_IN_ROOM(grub1, LEAF+"gnatsgrub");
	PLACE_IN_ROOM(grub2, LEAF+"gnatsgrub");
	if (arg) return;
	items = ({ 
				"puddles", "Stinking puddles with gnat's grubs in them",
				"puddle", "A stinking puddle with gnat's grubs in it",
				"grubs","They will soon become nasty gnats",
				"gnat's grubs","They will soon become nasty gnats",
				"path","It's in very bad condition"
			});
}

TWO_EXIT( LEAF+"q2","northwest",
           	HOME+"circular/circ6","southeast",
       	 "A dingy, badly kept path",
"A dingy, badly kept path, covered with puddles. Mildew grows on everything\n"+
"here.\n", 1)

