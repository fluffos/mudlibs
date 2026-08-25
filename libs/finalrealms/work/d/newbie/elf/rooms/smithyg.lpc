#include "path.h"

inherit "/std/room";
 
void setup () {
	add_property("no_undead",1); set_short("Realm of the Elf:  Bottom of the Staircase");
	set_long("\n   Realm of the Elf:  Bottom of the Staricase\n\n"
	"     You finally reach the bottom of the spiral staircase.  A "
		 "formidable sentry guards an iron-bound oaken door to the "
		 "west.  He looks at you warily.\n");

     /*Milord, mayhap 'tis best to create two of the sentry...one that doth*
      *not attack on sight, and one that doth.  Alas, I know not how to create*
      *such a one... */
	set_light(50); /*partially-lit room */

	add_exit("up", ROOM + "smithyf", "standard");
	//add_exit("west", ROOM + "smithyh", "door");

	set_zone("elves");
}
