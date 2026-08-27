#include "tweaks.h"
#define LOCK_PROP "flipped"
void attack_all(object ob);

int go_berserk(string str,object x)
{
   object me; 
   int BONUS, i;
   int BOVINES;
   int TIME;

   if(x) me = x;
   else me = this_player();
   if(me->query_property(LOCK_PROP))
   {
     tell_object(me,"You are already Berserk!\n");
     return 1;
   }
   if(me->query_gp()<=1)
   {
     tell_object(me,"You are too tired to go berserk.\n");
     return 1;
   }
   BONUS=((int)me->query_level()/3)+2;
   TIME=1+(int)(me->query_gp())/2;
   me->set_gp(0);
   me->adjust_tmp_damage_bon(BONUS);
   me->adjust_tmp_tohit_bon(BONUS/4);
   me->adjust_tmp_ac_bon(-4);
   me->add_timed_property(LOCK_PROP,1,TIME);	
   attack_all(me);	
   return 1;
 
}
 
attack_all(object ob)
{
 object *cows;
 int x;
 
 ob->set_wimpy(0);
 
 if(ob->query_gp()) { ob->set_gp(0); }
 cows=all_inventory(environment(ob));
 if(!(int)environment(ob)->query_property("noguild"))
 if(!(ob->query_property("dead")))
 
 for(x=0; x<sizeof(cows); x++)
 {
    if(!(cows[x]->query_property("dead")))
    if (!cows[x]->query_invis())
    if ( (int)cows[x]->query_hide_shadow() < (int)ob->query_level()/2 + (int)ob->query_int() )
    {
      ob->attack_ob(cows[x]);
    }
 }

 if(ob->query_attacker_list())
 {
    tell_room(environment(ob),ob->query_cap_name()+" screams in Berserk rage!\n");
 }

  if(!ob->query_property(LOCK_PROP)) end_berserk(ob);
  else call_out("attack_all",5,ob);
}
 
end_berserk(object ob)
{
   object me;
    int BONUS;
   me = ob;

    tell_object(me,"You become exhausted and are no longer berserk.\n");
    BONUS=((int)me->query_level()/3)+2;
    ob->adjust_tmp_ac_bon(4);
    if((int)ob->query_con() > 2) ob->adjust_tmp_con(-2);
    ob->adjust_tmp_damage_bon(-(BONUS));
    ob->adjust_tmp_tohit_bon(-(BONUS/3));
}
 
 
reset_berserk()
{
 this_object()->remove_timed_property(LOCK_PROP);
 return 1;
}
 
