#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object loot1 /*, loot2*/ ;
object grub, louse1, louse2, must;

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Monsters in this area are non-aggressive as long as the place\n"
		+"is marked as safe. Lots of food can be found here. The monsters\n"
		+"get tougher the further you go to the west.\n";
}
extra_reset(arg) { 
	loot1 = 0;
	PLACE_IN_ROOM(louse1, LEAF+"louse");
	PLACE_IN_ROOM(louse2, LEAF+"louse");
	PLACE_IN_ROOM(grub, LEAF+"gnatsgrub");
	FRESH_IN_ROOM(must, LEAF+"must");
	if (arg) return;
	items = ({ 
				"paths", "Two badly kept paths are to the north and south",
				"path", "A badly kept path",
				"bottom","It's covered with musts",
				"musts","They are covering the entire bottom here",
			});
}

FOUR_EXIT( 
			LEAF+"q3","northwest",
			LEAF+"q8","west",
			LEAF+"q13","southwest",
           	HOME+"circular/circ6","east",
       	 "A messy place in between some paths",
"A messy place in between some paths. The place is dimly lit and the bottom\n"+
"covered with musts.\n", 1)

dig(player) {
	if ("/players/qclxxiv/qquest/qmast"->lock_name2key(3,
			this_player()->query_real_name())==5) {
		if (!loot1) {
			PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map3");
			loot1->setup_map(this_player());
			log_file("qmap",this_player()->query_real_name()+" map3 "
						+ctime(time())+"\n");
			write_file("/players/qclxxiv/qquest/qmap",
					this_player()->query_real_name()+" map3 " +ctime(time())+"\n");
			return "You find a piece of map.\n";
		}
		else {
			return "You get the feeling someone was here earlier....\n"
					+"But maybe you just have to try later.\n";
		}
	}
	return "You find nothing.\n";
}
