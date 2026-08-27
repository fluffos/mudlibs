
/* Poison object, actually a "dead" invisible NPC 
 * Effects based on con, once cast this isn't a spell
 * but a festering wound
 */ 
#include "tweaks.h"
inherit "/obj/monster";

object strength;
int hb;

int dispell_me()
{
   this_object()->dest_me();
   return 1;
}
void init()
{
   ::init();
   set_heart_beat(1);
}
void set_spell(object ob,int damage)
{
    strength = damage;
}

void setup()
{
   set_name("poisoned wound");
   set_short("festering poisoned wound");
   set_race("monster");
   add_alias("wound");
   set_long("\n A disgusting looking wound that is weeping greennish puss and making you feel quite ill"
   "\n");
   set_get();
   reset_drop();
   set_gender(0);
   strength = random(20);
}
void heart_beat()
{
     object ob;
     int i;
     ::heart_beat();
      hb++;
     
     ob = environment(this_object());
     if(!ob || ob->query_property("dead") || !ob->query_timed_property("poisoned") )
     {
	  dispell_me();
     } 
     if(hb > ob->query_con() )
     {
	hb = 0;
	ob->adjust_hp(-random(strength),this_object());
	tell_object(ob,"Your poisoned wound weakens you.\n");
   tell_room(environment(ob),(string)ob->query_cap_name()+" suddenly looks ill.\n",({ ob }) );
     }
   set_heart_beat(1);
}     
