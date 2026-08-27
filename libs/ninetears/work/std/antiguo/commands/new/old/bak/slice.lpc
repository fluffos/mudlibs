
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


int slice(string str, object doer) {
   int skill,s1,i;
   int j;
   int damage;
   int bonus;
   object me;
   object *weap;
   object *vlist;
   object victim;

   me = doer ? doer : this_player();
   if (!str)
   {
      notify_fail("You are you trying to slice?\n");
      return 0;
   }

   weap = (object *)me->query_held_ob();
   vlist = find_match(str, environment(me));
   if(!sizeof(vlist))
   {
      notify_fail("Fantasizing about sliceing someone?  Try someone that is here.\n");
      return 0;
   }

   victim = vlist[0];
   if(victim->query_property("dead"))
   {
      tell_object(me,"Attacking up a ghost ?.\n");
      return 1;
   }
   if(victim->query_property("pacify_on"))
   {
      tell_object(me,"Nah, this ones way too harmless to attack ?.\n");
      return 1;
   }
   if(victim == me)
   {
      notify_fail("Slicing yourself? that's bright.\n");
      return 0;
   }
   if(me->query_property("slicing"))
   {
    tell_object(me, "You try to work up to a slice but are too "
    "unskilled and waste some effort.\n");
    me->adjust_gp(-2);
    return 1;
   }
  me->add_timed_property("slicing", 1, SLICE_LOCKOUT / (int)me->query_level() + random(3) );
   if((int)me->adjust_gp(-SLICE_COST) <= 0)
   {
	tell_object(me,"You don't have enough energy to slice!  Try again later.\n");
      return 1;
   }
  if (!weap[0] && !weap[1])
   {
      tell_object(me,"Slice with what?\n");
      return 1;
   }
   
   tell_object(victim,(string)me->query_cap_name()+" twirls "
    "and slices into you with a flurry of lightning\nquick attacks!\n");
    tell_object(me, "You slice into "+victim->query_cap_name()+
    " with a flurry of lightning quick attacks!\n");
  tell_room(environment(me), me->query_cap_name()+
    " twirls "+me->query_possessive()+" blades and slices into "+
    victim->query_cap_name()+" with a flurry of\n"
    "lightning quick attacks!\n", ({ me, victim }) );
   victim->attack_by(me);
  bonus = ( (int)me->query_level() * 1/8 ) + 4;
   if((string)me->query_race() == "drow")
      me->adjust_tmp_tohit_bon(bonus);
   for(i=0; i <((int)me->query_dex()+(int)me->query_level())/SLICE_DIV; i++)
   {
    if (weap[0]) weap[0]->weapon_attack(victim,me);
    if (weap[1]) weap[1]->weapon_attack(victim,me);
   }
   if((string)me->query_race() == "drow")
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
  "the more often you'll be able to hit.  As a rough guideline, "
  "at level 10, about 6 rounds per slice, level 20, 4 rounds per "
  "slice, level 30, 1 round between slices.  Before level 10, "
  "the lockout is much higher, but also grows less "
  "a lot quicker.\n";
}

