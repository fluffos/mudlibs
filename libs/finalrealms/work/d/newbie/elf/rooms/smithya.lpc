#include "path.h"

inherit "/std/outside";

void setup() {
	add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
	set_long("\n   Realm of the Elf:  Gloomy Forest\n\n"
	"     You stand before a huge-boled tree.  As you gaze up its trunk"
		 " you see boughs spreading thickly above you.\n");

	set_light(60);

	add_item("tree", "The trees here are for the most part ancient and "
			 "stately, although you see much new growth.\n");

	add_alias("leaves", "leaf");
	add_alias("trunks", "trunk");
	add_alias("trees", "tree");
	add_alias("boughs", "bough");

	add_item("trunk", "The trunks of the trees in this forest are huge -- "
			  "much larger than the armspan of two humans.  The "
			  "bark on the tree in front of you looks rough and "
			  "shaggy.\n");

	add_item("bark", "As you look closely, you discover hand- and foot-"
			 "holds worked into the rough bark.\n");
			 
	add_item( ({"hand-hold", "foot-hold"}), "These natural-looking "
		                 "indentations in the bark seem worn, as if "
			         "from much use.\n");

	add_item("floor", "The forest floor is carpeted with a thick pad of "
			  "fallen leaves.  They are quite springy and make for "
			  "pleasant walking.\n");

	add_item("sky", "Vivid blue peeks between thick foliage, giving the "
			"forest floor a peaceful dappled quality.\n");

	add_item("leaf", "The green leaves spreading above you glimmer in the "
			 "filtered sunlight.\n");

	add_item("bough", "Thick branches spread above you, their leaves  "
			  "forming a natural ceiling for this part of the "
			  "forest.\n");
	add_exit("north", ROOM+ "forest21", "plain");
	add_exit("south", ROOM+ "forest12", "plain");
	add_exit("east", ROOM+ "forest17", "plain");
	add_exit("west", ROOM+ "forest16", "plain");
	add_exit("up", ROOM + "smithyb", "hidden");

set_zone("elves");
}
