
#include "/d/gremios/comandos/tweaks.h"
/* Slice Taniwha 1995
 * An attack specific to drow warriors, since it can be used while IN combat
 * it should do less than backstab or slice
 * It is based on level AND dexterity
 * The number of extra attacks are (DEX / 9)* 3
 * at this stage
 * Frequency of use is (SLICE_LOCKOUT - level)  (SLICE_LOCKOUT noninally 40)
 * Cost is 1 GP/level
 * Use it too soon and you drop your weapons
 */
int hb_spell(object me, mixed *params);


int slice(string str, object doer) {
   int skill,s1,i;
   int j;
   int damage;
   int bonus;
   int hits;
   object me;
   object *weap;
   object v_round;
   object protectr;
   object *vlist;
   object victim;
   me = doer ? doer : this_player();
   if (!str)
   {
        notify_fail("You are you trying to slice?\n");
        return 0;
   }
   vlist = find_match(str,environment(me));
   weap =   (object *)me->query_held_ob();

   if(!sizeof(vlist))
   {
     notify_fail("Fantasizing about slicing someone?  Try someone that is here.\n");
     return 0;
   }
   victim = vlist[0];
   me->adjust_gp(-4); // Lose some GP whatever, to stop slice being spammed

   if(me->query_property("pacify_on"))
   {
      return 1;
   }
   if(victim->query_dead())
   {
      tell_object(me,"Attacking up a ghost?\n");
      return 1;
   }
   if(victim->query_property("pacify_on"))
   {
     tell_object(me,"Nah, this one's way too harmless to attack.\n");
     return 1;
   }
   if(victim == me)
   {
     notify_fail("Slicing yourself? That's bright.\n");
     return 0;
   } 
   if(me->query_property("slicing"))
   {
      tell_object(me, "You try to work up to a slice but are too "
      "unskilled and waste some effort.\n");
      return 1;
   }

   me->add_timed_property("slicing", 1, (SLICE_LOCKOUT / (int)me->query_level())
    + random(3) );
   if (!weap[0] && !weap[1])
   {
      tell_object(me,"Slice with what?\n");
      return 1;
   }

   bonus = ( (int)me->query_level() *  3/2 ) + 2;
   hits = ((int)me->query_dex()+(int)me->query_level())/SLICE_DIV;
   me->add_spell_effect(hits, "offensive","slice", this_object(),
        "hb_spell", ({ bonus,victim }));

   tell_object(victim,(string)me->query_cap_name()+" twirls "
     "and slices into you with a flurry of lightning\nquick attacks!\n");
   tell_object(me, "You slice into "+victim->query_cap_name()+
     " with a flurry of lightning quick attacks!\n");
   tell_room(environment(me), me->query_cap_name()+
     " twirls "+me->query_possessive()+" blades and slices into "+
      victim->query_cap_name()+" with a flurry of\n"
     "lightning quick attacks!\n", ({ me, victim }) );
   victim->attack_by(me);
   hb_spell(me,({bonus,victim}));
   return 1;
}
int hb_spell(object me, mixed *params)
{
   object protectr,victim,v_round;
   object *weap;
   int bonus;

   bonus = params[0];
   victim = params[1];
   weap =   (object *)me->query_held_ob();

   if( !victim || (environment(me) !=  environment(victim)) )
      return 0;

   if(environment(me)->query_property("no_guild")) return 0;

   // Fix By Wonderflug.  Hit protector possibly.  nov '95
   protectr =  victim->query_protector();
   if( protectr && environment(protectr) !=  environment(victim) ) protectr = 0;

   if(victim->query_property("no_slice")) bonus = 0;

   me->adjust_tmp_tohit_bon(bonus);
   if(me->adjust_gp(-2) > 0)
   {
      if ( protectr && protectr->query_protect_valid(victim, me) )
      {
            tell_room(environment(me), protectr->query_cap_name()+
              " valiantly protects "+victim->query_cap_name()+".\n",
              ({ me, protectr, victim }) );
            tell_object(victim, protectr->query_cap_name()+
              " valiantly protects you!\n");
            tell_object(me, protectr->query_cap_name()+
              " protects "+ victim->query_cap_name()+" from your attack!\n");
            tell_object(protectr, "You protect "+victim->query_cap_name()+
              " from "+me->query_cap_name()+"'s attack!\n");
            v_round = protectr;
       }
       else v_round = victim;
       tell_object(me,"You twirl your blades and slice into "+victim->query_cap_name()+".\n");
       if(weap[0] && weap[0]->query_attack_type() == 1)
         weap[0]->weapon_attack(v_round,me);
       if(weap[1] && weap[1]->query_attack_type() == 1)
         weap[1]->weapon_attack(v_round,me);
       v_round->attack_by(me);
   } else tell_object(me,"Whoops, you messed that up big time.\n");
   me->adjust_tmp_tohit_bon(-bonus);
   return 1;

}
string help(string str) {
  return
    "Syntax: slice <person>\n\n"
    "Slice is a Drow Warrior attack based on their skill with bladework. "
    "You get a series of extra blows, the number based "
    "upon your level and dexterity.  The higher level you are, "
    "the better chance you'll have to hit on each blow, and "
    "the more often you'll be able to hit. "
    "At present slice costs 4GP + 2GP per extra round of attacks.\n"
    ;
}



