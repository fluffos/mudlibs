inherit "/std/guildroom";
#include "path.h"
#define MAX 4

object board, sunmist, sign, *helpers;
int making_helper;

void reset()
  {
   if (!sunmist)
     {
      sunmist = clone_object(CHARS+"sunmist");
      sunmist->move(this_object());
   }
   if (!helpers)
      helpers = ({ });
}

void setup() {
   object sign;
   set_short("Clerics Guild of lathander");
   set_long("This is the heart of the temple of Lathander.  Here the priests "+
      "learn their spells and practise their skills.  The " +
      "guild gives you skills that relate to healing and turning the " +
      "undead minions.  You will also get a certain amount of help in " +
      "defending yourself in combat as priests are a bunch very " +
      "susceptible to pain.  They also get at high levels the abilty to " +
      "give people extra lives and at much lower levels refresh the " +
      "character anew.  Type \"info\" for information about this guild, " +
      "or \"pray\" to pray for a new spell.\nThere is a sign here.\n");
   sign = add_sign(
      "A decorative sign hangs on the wall by the entrance.  The sign " +
      "looks relatively new and clean.\n", ""+
      "      _______________________________________________________    \n"+
      "     |\\_____________________________________________________/|   \n"+
      "     | |                                                   | |   \n"+
      "     | |   WELCOME TO THE CLERICS GUILD OF LATHANDER       | |   \n"+
      "     | |                                                   | |   \n"+
      "     | |  - Type 'join' to become a member of this guild   | |   \n"+
      "     | |  - Type 'info' to get some guild-information      | |   \n"+
      "     | |  - Type 'advance <skill>' to advance your levels  | |   \n"+
      "     | |  - Type 'cost all' to see how much it will cost   | |   \n"+
      "     | |    to improve skills, or 'cost <skill>            | |   \n"+
      "     | |  - Type 'pray' to get a list of spells you can    | |   \n"+
      "     | |    pray for, or pray <spell> to get a spell       | |   \n"+
      "     | |  - Type 'specialize' to specialize on this God.   | |   \n"+ 
      "     | |  - Type 'convert' to convert to Lathander. This   | |   \n"+
      "     | |    must be done to learn spells here if you are   | |   \n"+
      "     | |    not a member of this guild. If you have already| |   \n"+
      "     | |    converted to another God you can't do this     | |   \n"+
      "     | |___________________________________________________| |   \n"+
      "     |/_____________________________________________________\\|\n\n");
   
   set_light(100);
   add_exit("south", ROOM+"lath11", "door");
   add_exit("north", ROOM+"lath12", "door");
   modify_exit("north", ({"function", "go_north" }) );
   set_teaching_person("liam");
   set_guild("priests/lathander");
   add_specialization("lathander");
}

void event_fight_in_progress(object ob1, object ob2) {
   int i;
   if (making_helper) return;
   if (random(100) > 80) {
      call_out("create_helper",0);
      making_helper = 1;
   }
   for (i=0; i<sizeof(helpers); i++)
   if (helpers[i] && environment(helpers[i]) == this_object()) {
      if (ob1 != sunmist) 
         if ((string)ob1->query_name() != "cleric")
         helpers[i]->attack_ob(ob1);
      if (ob2 != sunmist) 
         if ((string)ob2->query_name() != "cleric")
         helpers[i]->attack_ob(ob2);
   }
}

void create_helper() {
   object h;
   if (sizeof(helpers) > MAX)
      return ;
   h = clone_object("/obj/monster");
   h->set_name("cleric");
   h->set_short("cleric of Lathander");
   h->set_main_plural("clerics of Lathander");
   h->add_plural("clerics");
   h->set_long(
      "A cleric who has been roused from hard studies by a fight.\n");
   h->set_race("human");
   h->set_gender(1+random(2));
   h->set_class("cleric");
   h->set_level(10);
   h->init_equip();
   helpers += ({ h });
   call_out("run_in", 3, h);
   remove_call_out("still_fighting");
   call_out("still_fighting", 240);
}

void run_in(object h) {
   int i, j;
   object *obs;
   making_helper = 0;
   h->move(this_object());
   say(capitalize((string)h->short())+" stops studying and joins the "+
      "fight.\n");
   h->init_command("'Sunmist is under attack, help him!!!");
   if (sunmist) {
      obs = (object *)sunmist->query_attacker_list();
      for (j=0; j<sizeof(obs); j++)
      h->attack_ob(obs[j]);
   }
   for (i=0; i<sizeof(helpers); i++)
   if (helpers[i]) {
      obs = (object *)helpers[i]->query_attacker_list();
      for (j=0; j<sizeof(obs); j++)
      h->attack_ob(obs[j]);
   }
}

int still_fighting() {
   int s, i;
   if (sunmist)
      s += sizeof((mixed *)sunmist->query_attacker_list());
   for (i=0; i<sizeof(helpers); i++)
   if (helpers[i])
      s += sizeof((mixed *)helpers[i]->query_attacker_list());
   if (!s) {
      for (i=0;i<sizeof(helpers);i++)
      call_out("leave_room", 5+random(20), helpers[i]);
      helpers = ({ });
   }
}

void leave_room(object ob) {
   if (!ob) return;
   say(capitalize((string)ob->short())+" senses there's no danger to " +
      "Sunmist anymore, and returns to do some studying.\n");
   ob->dest_me();
}

void dest_me () {
   int i;
   for (i=0; i<sizeof(helpers); i++)
   if (helpers[i])
      helpers[i]->dest_me();
   if (sunmist)
      sunmist->dest_me();
   if (sign)
      sign-> dest_me ();
   ::dest_me ();
}

int go_north() {
   if((string)this_player()->query_level()<5)
   {
      tell_room(environment(this_player()),
         this_player()->query_cap_name()+" tried to go north, but was "+
         "stopped by and invisible force from Lathander.\n",
         this_player());
   notify_fail("The voice of Lathander fills you head: \"You must "+
      "have more faith in me before you can enter this room.\"  You are "+
      "stopped from going farther.\n");
   return 0;
   }
   return 1;
}
