#include "path.h"

inherit FORESTROOM;

void setup() {
	add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
	set_long("\n   Realm of the Elf:  Gloomy Forest\n\n"
	"     You meander deeper into the forest.  It is cool and quiet "
		 "here, shaded but not gloomy.\n");

	set_light(60);

	add_alias("leaves", "leaf");
	add_alias("trunks", "trunk");
	add_alias("trees", "tree");

	add_item("tree", "The trees here are for the most part ancient and "
			 "stately, although you see much new growth.\n");


	add_item("trunk", "The trunks of the trees in this forest are huge -- "
			  "much larger than the armspan of two humans.\n");

	add_item("floor", "The forest floor is carpeted with a thick pad of "
			  "fallen leaves.  They are quite springy and make for "
			  "pleasant walking.\n");

	add_item("sky", "Vivid blue peeks between thick foliage, giving the "
			"forest floor a peaceful dappled quality.\n");

	add_item("leaf", "The green leaves spreading above you glimmer in the "
			 "filtered sunlight.\n");
	add_exit("north", ROOM+ "forest20", "plain");
	add_exit("south", ROOM+ "forest11", "plain");
	add_exit("east", ROOM+ "smithya", "plain");

set_zone("elves");
}
