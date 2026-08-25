/*  Text alterations and replacement by Grimbrand 2-1-96                */

#include "path.h"
inherit "/std/underground";

void setup() {
  add_property("no_undead",1); set_light(10);
set_short("Realm of the Duergar:  Proving Grounds, Hidden Chamber");
set_long("\n   Realm of the Duergar:  Proving Grounds, Hidden Chamber.\n\n"
	 "     This room looks like one of the caves that you would "
	 "see out in the underdark.  Naturally rough rock walls, lit "
	 "by a strange glowing moss that is growing on the walls adds " 
	 "an eerie yet beautiful effect.  This room, when compared to "
	 "the others seems to be absolutely untouched by the hands of "
	 "any mortal.  The rock and crystal formations are absolutely "
	 "breathtaking, truely the work of the gods themselves.  The "
	 "stalagmites and stalagtites are all perfectly formed and "
	 "glisten with the moisture that provides their growth.  These "
	 "stone spires look to be just perfect for being turned into "
	 "blocks by a skilled miner.\n"
	 "\n");

add_item(({"formation", "formations", "rock formations", 
	   "crystal formations"}),
	 "   As you look around the room, you can see rock formations "
	 "of every shape and kind.  There are even a few geodes with "
	 "their swirl of crystal colors in the center of the plain "
	 "looking exterior.\n\n");

add_item(({"rock", "rocks"}),
	 "   You see so many different varieties of both rock and "
	 "mineral you hardly feel able to possibly identify "
	 "what they all are.\n\n");

add_item(({"crystals", "crystal"}),
	 "   Crystals of every color of the rainbow can be "
	 "seen spread across the room.  There are even a few that "
	 "are so warm their color pierces into the night vision "
	 "spectrum of underdark creatures.  These warm crystals "
	 "are quite valuable, unfortunately the ones here aren't big "
	 "enough to bother with.\n\n");

add_item(({"wall", "walls"}),
	 "   The walls seem to be made of some kind of slate, "
	 "but it's just too difficult to tell.\n\n");

add_item("moss",
	 "   As you look at the moss, you can see that it is "
	 "growing directly upon the rock.  It gives off a blueish "
	 "glow that helps to light the area up enough to where you "
	 "can see fairly well.\n");

add_clone(DNPC+"rat",3);
   add_exit("east",NEWBIE+"dlev1_03","door");
   add_exit("north",NEWBIE+"dlev1_10","door");
   add_exit("west",NEWBIE+"dlev1_08","door");
}
