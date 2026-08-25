/*  Text alterations and additions by Grimbrand 2-3-96                */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"duggan");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
set_short("Realm of the Duergar:  Guild Masters Office");
set_long("\n   Realm of the Duergar:  Guild Masters Office.\n\n"
	 "     You have entered the Guild Masters Office.  It is through "
	 "here that all Duergar come to train to be able to survive "
	 "in the realms.  The room is lightly furnished, with only a "
	 "desk and a chair.  Yet the walls are covered with lavish "
	 "murals depicting various events.  The hangings must be "
	 "priceless, because of the intricate work that must have " 
	 "gone into making them.  The Master sits in his chair "
	 "patiently waiting for you to give him your undivided "
	 "attention.  It would be wise to \"listen\" to what he has to "
         "say."
         "\n\n");

add_exit("north",NEWBIE+"main02","door");
add_exit("south",BUILD+"dhall1","door");
modify_exit("south",({"function","bounced"}));
modify_exit("north",({"function","bouncer"}));
}

void dest_me() {
   int i;
   for(i=0;i<sizeof(npcs);i++)
   if(npcs[i]) npcs[i]->dest_me();
   ::dest_me();
}
 
int bouncer() {
int lv;
object me = this_player();
lv = (int)me->query_level();
if(lv <= 4) {
write("You push on the door, and it opens without a sound.  Someone "
	 "took their time oiling its hinges.\n\n");
tell_room(environment(me), me->query_cap_name()+" pushes on the door to the "
	 "north, and it swings open freely allowing them to pass.\n\n",
	 ({this_player()}));
   return 1;
}
notify_fail("You are unable to open the door.\n\n");
tell_room(environment(me), me->query_cap_name()+" tries to open the door to "
	"the north but fails.\n\n",({this_player()}));
return 0;
}

int bounced() {
int lv;
int xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
//if(lv>=5&&xp>30000) { me->adjust_xp(-xp+1000); }
if(lv >= 5){
write("You open the door leading out into the realms from the Academy"
"\n\n");
tell_room(environment(me), me->query_cap_name() +" pushes on the "
	"door to the south leaving the Academy.\n\n",
	({this_player()}));
   return 1;
}
notify_fail("You have not earned the right to leave the Academy yet!"
	    "\n\n");
tell_room(environment(me), me->query_cap_name() +" thinks about leaving "
	"the Academy but decides not to since "+
	 this_player()->query_pronoun()+" hasn't finished "+
	 this_player()->query_possessive()+" training yet.\n\n",
	 ({ this_player() }));
   return 0;
}
