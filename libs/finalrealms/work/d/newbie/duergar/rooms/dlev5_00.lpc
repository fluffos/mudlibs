/*  Text alterations and additions by Grimbrand 2-4-96                  */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster04");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
   add_property("no_undead",1); set_light(10);
   npcs = allocate(1);
   
   set_short("Realm of the Duergar:  Lore Masters Office");

   set_long("\n   Realm of the Duergar:  Lore Masters Office.\n\n"
	    "     Entering the office of the Lore Master you realize that "
	    "he is here to teach young duergar how to identify the "
	    "various races found throughout the realms.  The room is "
	    "very spartanly furnished with only a desk and a chair for the "
	    "lore master to use.  It might be wise to \"listen\" very "
	    "closely to his speech."
	    "\n\n");

   add_item("desk",
	    "   The desk appears to made out of some kind of hard, "
	    "dark wood.  Upon the desk you can see quite a few scattered "  
	    "papers giving it a cluttered look."
	    "\n\n");

   add_item("chair",
	    "   The chair behind the desk looks to be incredibly "
	    "comfortable and made by what could only be the finest of "
	    "craftsmen."
	    "\n\n");

   add_item(({"papers","paper"}),
	    "   Looking at the papers scattered across the desk, you begin "
	    "to make out what looks to be a list of names.  Some of the "
	    "names seem to have been marked out with a reddish-brown "
	    "colored ink.  Peering closer you start to read the first name "
	    "which is\n\n"
	    "Girthwer snatches the list from the desktop and quickly shoves "
	    "it into his pocket.\n\n"
	    "Girthwer says: Why don't ye mind yer own business!"
	    "\n\n");

   add_exit("north",NEWBIE+"dlev5_01","door");
   add_exit("south",NEWBIE+"main03","door");
   modify_exit("north",({"function","bouncer"}));
}

void dest_me() {
int i;
/* if we kill off the room, kill off the contents as well */
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 
int bouncer() {
int lv,xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 4 && xp < 20500) {
write("   The heavy door opens silently, allowing you to enter the next "
	 "room.\n\n");
tell_room(environment(me), me->query_cap_name()+" steps towards the "
	 "door and it opens quietly, allowing "+me->query_objective()+
	 " to enter the room beyond.\n\n",
	 ({this_player()}));
return 1;
}
notify_fail("   You try to enter the training area, but the door doesn't " 
	    "open.\n\n");
tell_room(environment(me), me->query_cap_name()+
	 " is unable to enter the Training Area.\n\n",
	 ({this_player()}));
return 0;
}
