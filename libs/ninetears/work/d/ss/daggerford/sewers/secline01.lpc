#include "path.h"
inherit "/std/room";
inherit RESTOCK;

#define NUM 2

void setup()
	{set_short("Secondary Sewer Line");
	set_long("The torch in this room burns low, adding a grim"+
		" feeling to the atmosphere.  Raw sewage from the"+
		" city above you rushes by, flowing toward the main"+
		" sewer line.  The walls shine with moisture, and"+
		" a small draft causes the torch flame to flicker.\n");
	add_item(({"walls","moisture"}), "The walls are slick with"+
		" the wet, humid fumes of sewage.\n");
	add_item("sewage", "The refuse of Daggerford flows by you,"+
		" carrying with it a smell of spoiled milk and"+
		" rotten eggs.\n");
	add_item("torch", "The torch has been burning for a long time"+
		" and is now almost burnt out.  Whoever is supposed to"+
		" care for the maintenance here has been"+
		" sadly negligent.  Typical city worker...\n");
	set_light(SECONDARY);
	set_zone("sewers");

	/add_exit("north...etc.
	modify_exit...need Falco's files. /
	add_exit("south", SEWERS+"secline02", "corridor");
	modify_exit("south", ({"message", "N$N heads off to the south"+
		", splashing through the sewage.\n"}));
}
		" rotten eggs.\n");
