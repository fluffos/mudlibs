#include "path.h"

inherit "/std/room";
 
void setup () {
	add_property("no_undead",1); set_short("Realm of the Elf:  Eldevan's Showroom");
	set_long("\n   Realm of the Elf:  Eldevan's Showroom\n\n"
	"     This small room displays some of Eldevan's best work.  "
		 "Finely-honed and wicked-looking blades adorn the walls, "
		 "and suits of plate armour and chainmail stand in the "
		 "northwest and northeast corners of the room, respectively.  "
		 "There is a display case in the center of the room.\n");

	/*This room doth contain extensive descriptions of items....Dost thou 
	*think I should also create the items, most notably the suits of armor?
	*Or dost thou believe the descriptions should suffice?
	*/
	set_light(60); /*well-lit room */

	add_alias("blades", "blade");
	add_alias("daggers", "dagger");
	add_alias("swords", "sword");

	add_item("blade", "Two daggers occupy places of honor on either side of "
			  "the door.  A rapier is centered on the west wall "
			  "and a scimitar dominates the east.  On the north "
			  "wall, two short swords flank an immense greatsword.\n");

	add_item("dagger", "The dagger to the left is actually a main-gauche, "
			   "a companion piece to the dagger on the right.  They"
			   " both have intricate scroll work down the blade, "
			   "with golden hilts and ebony grips.\n");

	add_item("rapier", "An intricate basket-hilt protects the "
		   "leather-wrapped handgrip.  The slim blade glimmers "
			   "with deadly beauty.\n");

	add_item("scimitar", "The wide, curved blade is etched with ancient "
			     "Elven runes.  Devoid of other decoration, this "
			     "weapon is nonetheless a jewel of Eldevan's art.\n");

	add_item("sword", "These short swords are obviously a pair -- and they "
			  "have seen some use.  The point of the right one is "
			  "rounded slightly, as if it had been broken at some "
			  "time.\n");

	add_item("greatsword", "The elf who wielded this sword must indeed "
			       "have been great.  Fully five feet long, with "
			       "wicked barbs near the hilt, this blade is also"
			       " covered with ancient Elven runes.\n");

	add_item("plate", "Elven-sized and polished to a mirror gleam, the "
			  "plate armor brings to mind past glories.\n");

	add_item("chainmail", "The links in this chainmail are much smaller "
			      "than normal.  It moves in your fingers like "
			      "fine silk, and is lighter than it appears.  "
			      "It is made of a material you do not find "
		      "familiar.\n");

	add_item("armor", "The plate armor and chainmail have seen use, but "
			  "are in excellent condition.\n");

	add_item("case", "Displayed on black velvet are a shining great helm "
			 "and chainmail coif.\n");

	add_item("helm", "It appears to match the plate armor in the corner.\n");

	add_item("coif", "It appears to match the chainmail in the corner.\n");

	add_exit("south", ROOM + "smithyc", "standard");

	set_zone("elves");
}
