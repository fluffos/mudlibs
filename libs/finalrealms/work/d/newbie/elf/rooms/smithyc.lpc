#include "path.h"

inherit "/std/room";
 
void setup () {
	add_property("no_undead",1); set_short("Realm of the Elf:  Eldevan's Smithy");
	set_long("\n   Realm of the Elf:  Eldevan's Smithy\n\n"
	"     You have found the shop of Eldevan, armourer to those who "
		 "live in this forest.  His stock is small, but each piece "
		 "bears the fineness of Elven crafting.  A doorway to the north" 
		 " leads to a small showroom.\n");

	/*Milord, I do believe this room requires some sort of simple shop code.	*I would not have this area as a general store, but only an armory with
	*a limited stock.  Again, wilt thou add this code, or wilt thou instruct
	*me?
	*/
	set_light(60); /*well-lit room */

	add_exit("north", ROOM + "smithyd", "standard");
	add_exit("down", ROOM + "smithyb", "standard");
	add_exit("west", ROOM + "smithye", "door");
	set_zone("elves");
   add_clone(CHAR+"smith",1);
}
