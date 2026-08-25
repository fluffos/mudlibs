#include "path.h"

inherit "/std/room";
 
void setup () {
	add_property("no_undead",1); set_short("Realm of the Elf:  Hidden Staircase");
	set_long("\n   Realm of the Elf:  Hidden Staircase\n\n"
	"     You descend the dimly-lit spiral staircase cautiously.  "
		 "The steps seem to continue forever, swirling slowly down "
		 "into darkness.\n");

	set_light(50); /*partially-lit room */

	add_exit("up", ROOM + "smithye", "door");
	add_exit("down", ROOM + "smithyg", "standard");

	set_zone("elves");
}
