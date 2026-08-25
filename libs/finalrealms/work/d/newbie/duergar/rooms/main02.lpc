/*  Text alterations and additions by Grimbrand 2-3-96                   */

#include "path.h"
inherit "/std/underground";


void setup() {
   
   add_property("no_undead",1); set_light(10);

   set_short("Realm of the Duergar:  Hall");
   
   set_long("\n   Realm of the Duergar:  Hall.\n\n"
	    "     This is a very plain and unadorned room.  The only "
	    "feature of note is the single spiraling staircase leading "
	    "down.\n"
	    "\n");

   add_item(({"stair", "staircase", "stairway" "spiraling staircase"}),
	    "   This staircase is made of handcrafted metal.  The "
	    "worksmanship and attention to detail is exquisite!  "
	    "There is no doubt it has been made by master duergar "
	    "metalsmiths.\n"
	    "\n");

   add_exit("down",NEWBIE+"main03","door");
   add_exit("north",NEWBIE+"grubhall","door");
   add_exit("south",NEWBIE+"main01","door");
   add_exit("northeast",NEWBIE+"store","door");
   add_exit("east",NEWBIE+"guildrm","door");
}

