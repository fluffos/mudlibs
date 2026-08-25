#include "path.h"

inherit "/std/room";
 
void setup () {
	add_property("no_undead",1); set_short("Realm of the Elf:  Eldevan's Back Room");
	set_long("\n   Realm of the Elf:  Eldevan's Back Room\n\n"
	"     You have entered Eldevan's workroom, where he constructs and "
		 "repairs armour and weaponry.  He is often found here, working "
		 "diligently at his craft.\n");

	/*Master Eldevan must of needs be in this room...it is in my mind that 
	*given the correct command, he will lead the interested player down into
	*the hidden mithril smithy.  At the base of the trunk will be another
	*sentry...Should a player approach this sentry without Eldevan, he shall
	*attack immediately.  The sentry should be most puissant at arms, for he
	*doth protect the most precious craft of Elven armorers.  An thou art 
	*not able to create this thyself (because of thy current workload), 
	*canst thou instruct me thus?
	*/
	set_light(60); /*well-lit room */

	add_exit("east", ROOM + "smithyc", "door");

	set_zone("elves");
}
