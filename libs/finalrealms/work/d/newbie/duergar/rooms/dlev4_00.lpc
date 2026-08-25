/*  Text alterations and additions by Grimbrand 2-3-96                  */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster03");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
   add_property("no_undead",1); set_light(10);
   npcs = allocate(1);

   set_short("Realm of the Duergar:  Cavern Masters Office");
   
   set_long("\n   Realm of the Duergar:  Cavern Masters Office.\n\n"
	    "     This office is decorated with several different "
	    "types of hunting trophies, all of which hang proudly "
	    "upon the walls.  The Cavern Master is known well "
	    "for his prowess in combat and has retired from his "
	    "days as an adventurer to teach young Duergar like "
	    "yourself how to survive in the world.  Many \"listen\""
	    "to what he has to say for it could mean the difference "
	    "between life or death. You can see a large desk and "
	    "chair which obviously belong to the Cavern Master.  "
	    "To your northeast a door awaits your entry.\n"
	    "\n");

   add_item("trophies",
	    "   Looking at the trophies you see some sort of claw "
	    "or hook and several heads.\n\n");

   add_item(({"hook", "claw"}),
	    "   Looking at the huge hook hanging on the wall "
	    "behind the Cavern Masters desk, you recognize that it came "
	    "from a Hook Horror.  Judging from the size of the hook "
	    "it must have been at least four to five duergar tall "
	    "and extremely powerful.\n\n");

   add_item(({"head", "heads"}),
	    "   As you look at the heads on the far wall you "
	    "recognize a Umber Hulk and a Hell Hound.  It is said "
	    "that an Umber Hulk is a terrible foe, and come at you "
	    "unexpectedly through solid walls.  The Hell Hound on "
	    "the other hand is a fiend from the lower levels of "
	    "hell.  The Drow brought them forth into the underdark "
	    "in an attempt to guard their underground home "
	    "from any intruders.\n\n");

   add_item("desk",
	    "   The desk of the Cavern Master is truely a gruesome "
	    "sight to behold.  It has been built out of the bones of "
	    "the creatures he has killed in the underdark.\n\n");

   add_item("chair",
	    "   The only chair in the room rests behind the Cavern "
	    "Masters desk.  It looks like it is made out of some type "
	    "of surface dweller wood.\n\n");

   add_exit("northeast",NEWBIE+"dlev4_01","door");
   add_exit("southwest",NEWBIE+"main03","door");
   modify_exit("northeast",({"function","bouncer"}));
}

void dest_me() {
   int i;
   for(i=0;i<sizeof(npcs);i++)
   if(npcs[i]) npcs[i]->dest_me();
   ::dest_me();
}
 
int bouncer() {
   int lv,xp;
   object me = this_player();
   lv = (int)me->query_level();
   xp = (int)me->query_xp();

   if(lv == 3 && xp < 10000) 
     {
      write("   The door opens with a slight push, allowing just "
	    "enough room to let you pass.\n\n");
      tell_room(environment(me), me->query_cap_name()+" gives the door a "
		"slight push opening it just enough to let "
		+this_player()->query_objective()+" to"
		" pass through.\n",({this_player()}));
      return 1;
     }
      notify_fail("   You push on the door with all your might, but "
		  "it simply will not open.\n\n");
      
      tell_room(environment(me), me->query_cap_name()+" tries to push the "
                "door open with all "+this_player()->query_possessive()+
		" might to no avail.\n\n",
		({this_player()}));
      return 0;
}
