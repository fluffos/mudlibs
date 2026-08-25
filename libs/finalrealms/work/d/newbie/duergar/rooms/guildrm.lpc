/*  Text additions and alterations by Grimbrand 2-3-96                 */

#include "path.h"
inherit "/std/newbieguild";

object board;

void setup()
  {
   add_property("no_undead",1); set_light(20);

   set_short("Realm of the Duergar:  Adventurer's Guild Room");

   set_long("\n   Realm of the Duergar:  Adventurer's Guild Room.\n\n"
	    "     This is a small dimly-lit room where new duergar "
	    "adventurer's join the Training Guild.  The room is "
	    "very plain, the only thing of note is a sign on the "
	    "wall.\n"
	    "\n");
   
   add_item("sign","\nThe sign reads:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
"|           %^BOLD%^Duergar Adventurer's Guild%^RESET%^                |\n"
       "|                                                     |\n"
       "|      'cost' To find the XP cost to advance.         |\n"
       "|      'advance' To advance your skills.              |\n"
       "|      'info' To get some information.                |\n"
       "|                                                     |\n"
       "|      You cannot advance above level 5 here.         |\n"
       "|      To join type 'advance'.                        |\n"
       "|                                                     |\n"
       "+-----------------------------------------------------+\n"
       "\n");
   
   add_exit("west",NEWBIE+"main02","door");
  }
