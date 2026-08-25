/*  Text alterations and additions by Grimbrand 2-3-96                 */

#include "path.h"
inherit "/std/underground";

void setup() {
   
   add_property("no_undead",1); set_light(10);
   
   set_short("Realm of the Duergar:  Main Hall");
   
   set_long("\n   Realm of the Duergar:  Main Hall.\n\n"
	    "     You are in the main hall of the Duergar Academy.  "
	    "Unfortunately, the name is the only impressive thing that "
	    "you have seen so far.  The room is empty with bare rock "
	    "walls and only a few doors.  The doors have signs on  "
	    "them.\n"
	    "\n");

   add_item(({"sign", "signs"}),
            "\n"
            "     Each door has its own sign on it.\n\n"
	    "The sign on the North door reads:  Lore Masters "
	    "Office.\n"
	    "The sign on the South door reads:  Academy Raiseroom.\n"
	    "The sign on the Northeast door reads:  Cavern "
	    "Masters Office.\n"
	    "The sign on the Northwest door reads:  Surface "
	    "Explorations Office.\n"
	    "The sign on the door leading Down reads:  Mine Masters "
	    "Office.\n"
	    "\n");

   add_exit("north",NEWBIE+"dlev5_00","door");
   add_exit("south",NEWBIE+"raiserm","door");
   add_exit("northeast",NEWBIE+"dlev4_00","door");
   add_exit("northwest",NEWBIE+"dlev3_00","door");
   add_exit("down",NEWBIE+"dlev1_00","stair");
   add_exit("up",NEWBIE+"main02","stair");
}
