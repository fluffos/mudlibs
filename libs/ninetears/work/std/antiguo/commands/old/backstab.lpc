#include "tweaks.h"
#define LOCK_PROP "backstabing"

/* Backstab, made by someone, fixed by a gazillion immortals since it was 
 * born.  Latest fix by Taniwha, Manshoon and Baldrick, dec '94
 *
 * Latest addition by Wonderflug.  During fights.  sept '95
 */

void do_circle(object, object, int);

int already_attacking(object me,object victim)
{
  int i;
  object *list;
 
  if( member_array(me,victim->query_attacker_list()) != -1)
    return 1;
   if(member_array(me,victim->query_call_outed()) != -1) return 1;
  if( sizeof(me->query_attacker_list()) )
    return 2;
  return 0;
}

int backstab_damage(object me,object victim, object weapon)
{

/* Backstab damage is based upon level and dexterity of the attacker.
   A random element is added which equals the prev calculated dam.
   Which piercing weapon that is used has no effect. After all backstabbing
   is a skill, eh?    -Manshoon 14 Dec -94    */
   
  
  int lvl;
  int dam;
  lvl = me->query_level();
  dam = me->query_dex();
  if (dam>20) dam = 20; // hmm, anyone out there with super dex?
                        // Well, it won't help them, he he
  dam += (int)weapon->query_damage_roll();
  if (lvl < 15)
    dam *= (2 + lvl/2);
  else
    dam *= (5 + lvl/3);
   
  dam /= 10;
  dam += random(dam);  // Backstab surely needs random element    
  /* Baldrick; I just don't like players able to hit for more than
   * its own HP.
   */
  if (dam > me->query_max_hp())
    dam = me->query_max_hp();
  return(dam);
   
}

int sense_check(object me,object victim)
{
  int sense;
  int moi;
  if(!me->query_hide_shadow())
    return 1;  // Sensed if not hidden
		
  if( victim->query_property("sense_life") )
    return 1;  // add prop sen_life to npc's that you want
               // to be immune to backstabs.
	
  /* the best they can do, either native int or the gods are kind 
   * NOT both 
   */
  if(victim->query_int() > victim->query_wis() ) 
    sense = victim->query_int();
  else sense = victim->query_wis();

  sense += victim->query_level();

  sense = random(sense); // Always SOME chance of being hit
	
  moi = me->query_level() + this_player()->query_dex();
	
  if(moi < sense)
    return 1;  // You're sensed
  return 0;
}

int backstab(string str,object x) 
{
  int skill,s1,i,j;
  int damage, cost;
  object me;
  object *weap;
  object *vlist;
  object victim;
  string vname, aname, wname;  //victim name, attacker name, weapon name
 
  if(x) 
    me = x;  
  else 
    me = this_player();
  if (!str)
  {
    tell_object(me,"Better find a target first....\n");
    return 1;
  }
  if ( me->query_spell_effect("thief") )
  {
    tell_object(me, "You seem to be busy doing something else at the "
      "moment.\n");
    return 1;
  }

  weap = (object *)me->query_weapons_wielded();
  vlist = find_match(str,environment(me));
  if(!sizeof(vlist))
  {
    tell_object(me,"Backstab who ?\n");
    return 1;
  }
  victim = vlist[0];
  if(victim == me)
  {
    tell_object(me,"You try to backstab yourself, but luckily you "
      "can't reach that far behind you.\n");
    return 1;
  }
  if(victim->query_dead())
  {
    tell_object(me,"Ghosts don't have money.  No point backstabbing "
      "them.\n");
    return 1;
  }
  damage = 0;
  for (i=0;i<sizeof(weap);i++)
  {
    if((int)weap[i]->query_attack_type() == 3) 
    {
      damage += backstab_damage(me,victim,weap[i]);
    }
    else
    {
      tell_object(me,"It would be rather impossible to shove a "+
        weap[i]->query_short()+" in someone's back.\n");
      return 1;
    }
  }
  // making these to clear up the code for you. (yes you!)
  // Fix by !Aragorn
  if (!sizeof(weap)) 
  {
    tell_object(me,"Your fingers aren't really sharp enough to "
      "backstab someone with.\n");
    return 1;
  }

   
  // fix by !Aragorn
  if (i>=sizeof(weap)) i=0;

  wname = weap[i]->query_short();
  vname = victim->query_short();
  aname = me->query_short();   

  if( me->query_gp() < me->query_level())
  {
    tell_object(me, "You're too tired to backstab again.\n");
    return 1;
  }     
  if( (j=already_attacking(me,victim)) == 1)
  {
    do_circle(me, victim, damage);
    return 1;
  }
  else if ( j == 2 )
  {
    tell_object(me, "Wouldn't be a good idea to neglect your other "
      "attackers and backstab someone else.\n");
    return 1;
  }

  if(me->query_property(LOCK_PROP))
  {
    tell_object(me,"Your heart is beating so hard that you "
      "cannot backstab.\n");
    return 1;
  }
  me->add_timed_property(LOCK_PROP,100,BACKSTAB_LOCKOUT);

  /* OK, Gonna try add some chance for the victim to sense the 
   * backstab here.  Idea is that it should be fairly hard to sense 
   * a backstab, and to protect mages and clerics somewhat I will 
   * include wis and int into the test so they get a higher chance of 
   * avoiding a backstab than a dumb fighter.  -Manshoon  
   */
  if(sense_check(me,victim))
  {
    tell_object(me,"Oh bugger, "+vname+" seems to have sensed your "
      "intentions!\n");
  }
  else 
  {             
    victim->adjust_hp(-damage,me);
    cost = me->query_level();
    me->adjust_gp(-cost);
    tell_object(victim,"You convulse in agony as "+aname+" places a "+
      wname+" in your back!\nThat really did hurt!\n");
    tell_room(environment(me), vname+" convulses in agony as "+aname+
      " places a"+wname+" in "+victim->query_possessive()+" back!\n",
      ({ me, victim }) );
    tell_object(me,vname+" convulses in agony as you place a "+wname+
      " in "+victim->query_possessive()+", and blood pours over your "
      "hands.\n");
	
    // Removed the bit that wrote out the damage done.....
  }
  victim->attack_by(me); 
  return 1;
}

string help(string str) 
{
  return
"Syntax: backstab <person>\n\n"
"Backstab is based on your level and dextirity. "
"Your victim has a chance of sensing the backstab and thus avoiding "
"it based on his level, wisdom and intelligence. "
"Wether you are successful or not, the victim will attack you.\n\n"
"You need a piercing weapon to be able to backstab and you must be hidden.\n"
"The cost is level dependent.\n\n"
"You may also backstab during a fight, provided someone "
"is there to distract your opponent long enough for you "
"to work your way behind them.  In this case the cost is "
"4 GP per round of circling that you need to do.\n\n"
"Example\n"
"> backstab merchant\n";
}

void do_circle(object me, object him, int dam)
{
  object* alist;

  if ( sizeof((alist=him->query_attacker_list())) < 2 )
  {
    tell_object(me, "There isn't anyone to distract your victim "
      "long enough for you to circle round.\n");
    return ;
  }
  me->add_spell_effect(3+random(3), "thief", "backstab", this_object(),
             "hb_backstab", ({ him, (int)me->query_hp(), dam }) );

  tell_object(me,"You begin to edge around "+him->query_cap_name()+".\n");
}

void hb_backstab(object me, mixed params, int time)
{
  /* do checks */
  if ( !params[0] || environment(me) != environment(params[0]) ||
       already_attacking(me, params[0]) != 1 )
  {
    tell_object(me, "Your victim seems to have left.  Let the chase "
      "begin!\n");
    call_out("end_circle", 0, me);
    return ;
  }
  if ( me->query_dead() || params[0]->query_dead() ) 
  {
    tell_object(me, "You stop trying to circle your victim.\n");
    call_out("end_circle", 0, me);
    return ;
  }
  if ( (int)me->query_hp() != params[1] ||
      params[0]->query_attackee() == me ||
       random(100) > 50+(int)me->query_level()+(int)me->query_dex()
         - (int)params[0]->query_level() )
  {
    tell_object(me, "Oh bugger. "+params[0]->query_cap_name()+
      " seems to have noticed your intentions.\n");
    tell_object(params[0], "Just in time you notice "+
      me->query_cap_name()+" trying to slip around behind you!\n");
    params[0]->attack_by(me);
    params[0]->set_concentrate(me);
    call_out("end_circle", 0, me);
    return ;
  }
  if ( me->adjust_gp(-4) <= 0 )
  {
    tell_object(me, "You lose your patience..\nIn your haste you "
      "stumble and "+params[0]->query_cap_name()+" notices you!\n");
    call_out("end_circle", 0, me);
    return ;
  }
  if ( time != 1 )
  {
    tell_object(me, "You continue to work your way behind "+
      params[0]->query_cap_name()+"..\n");
    return 0;
  }
  params[0]->adjust_hp(-params[2], me);
  tell_object(me, "Seizing the moment, you plunge your weapon "+
    params[0]->query_cap_name()+"'s back.\n"+
    params[0]->query_cap_name()+" spasms in pain.\n");
  tell_object(params[0], "You spasm in pain as "+me->query_cap_name()+
    " plunges a long sharp object into your back.\nYou could have "
    "sworn "+me->query_pronoun()+" was in front of you!\n");
  tell_room(environment(me), me->query_cap_name()+" circles behind "+
    params[0]->query_cap_name()+" and backstabs "+
    params[0]->query_objective()+".\n",
    ({ params[0], me }) );
  params[0]->attack_by(me);
  params[0]->set_concentrate(me);
  return 0;
}

void end_circle(object me)
{
  me->remove_spell_effect("backstab");
}
