#include "path.h"

inherit "/std/outside";

void setup() {
	add_property("no_undead",1); set_short("Realm of the Elf:  Middle of the Tree");

	set_long("\n   Realm of the Elf:  Middle of the Tree\n\n"
	"     You have reached the midpoint of the trunk.  As you pause a "
		 "moment to rest, you notice a sentry post has been formed "
		 "at this point in the living tree.  Only great magic could "
		 "have done such a thing!\n");

 	/*Hokemj...this room doth require a sentry, one that doth seem to fade 
	*into the bark of the tree.  Wilt thou create one, or wilt thou instruct
	*me in the crafting thereof?
	*/

	set_light(60);

	add_alias("leaves", "leaf");
	add_alias("trunks", "trunk");
	add_alias("trees", "tree");

	add_item("tree", "The trees here are for the most part ancient and "
			 "stately, although you see much new growth.\n");


	add_item("trunk", "The trunks of the trees in this forest are huge -- "
			  "much larger than the armspan of two humans.\n");

	add_item("floor", "The forest floor, far below you, is carpeted with a "
		          "thick pad of fallen leaves.  They are quite springy, "
			  "but you doubt they would cushion your fall much.\n");

	add_item("sky", "Vivid blue peeks between thick foliage, giving the "
			"forest floor a peaceful dappled quality.\n");

	add_item("leaf", "The green leaves spreading above you glimmer in the "
			 "filtered sunlight.\n");
	add_exit("up", ROOM+ "smithyc", "standard");
	add_exit("down", ROOM+ "smithya", "standard");

}
