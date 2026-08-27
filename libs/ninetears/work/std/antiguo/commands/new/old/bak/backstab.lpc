#include "tweaks.h"
#define LOCK_PROP "backstabing"

/* Backstab, made by someone, fixed by a gazillion immortals since it was born.
 * latest fix by Taniwha, Manshoon and Baldrick, dec '95
 */

int already_attacking(object me,object victim)
{
   int i;
   object *list;
   if( sizeof(me->query_attacker_list()) ) return 1;
   if( member_array(me,victim->query_attacker_list()) != -1) return 1;
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
	
   /* the best they can do, either native int or the gods are kind NOT both */
   if(victim->query_int() > victim->query_wis() ) sense = victim->query_int();
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
   int skill,s1,i;
   int damage, cost;
   object me;
   object *weap;
   object *vlist;
   object victim;
   string vname, aname, wname;  //victim name, attacker name, weapon name
 
   if(x) me = x;  
   else me = this_player();
   if (!str)
   {
      tell_object(me,"Better find a target first....\n");
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
      tell_object(me,"You sit down and rest, pondering about how you can "
      		"backstab yourself.\n");
      return 1;
   }
   if(victim->query_property("dead"))
   {
      tell_object(me,"Attacking up a ghost ?.\n");
      return 1;
   }
   // set quite low now that they have to be fighting, BUT I know this can't be aliased past
   if(me->query_property(LOCK_PROP))
   {
       tell_object(me,"Your heart is beating so hard that you cannot backstab.\n");
       return 1;
   }
   me->add_timed_property(LOCK_PROP,100,BACKSTAB_LOCKOUT);	
   damage = 0;
   for (i=0;i<sizeof(weap);i++)
   {
      if((int)weap[i]->query_attack_type() == 3) /* same as dagger, pierce */
      {
         damage += backstab_damage(me,victim,weap[i]);
      }
      else
      {
      	 tell_object(me,"Backstab with a "+weap[i]->query_short()+" ?\n");
	 return 1;
      }
   }
   // making these to clear up the code for you. (yes you!)

   // Fix by !Aragorn
   if (!sizeof(weap)) {
      tell_object(me,"Need a wielded weapon for this action...\n");
      return 1;
   }

   
    // fix by !Aragorn
   if (i>=sizeof(weap)) i=0;

   wname = weap[i]->query_short();
   vname = victim->query_short();
   aname = me->query_short();   

  if( me->query_gp() < me->query_level())
  {
	tell_object(me,"Your adrenaline pumps to much for you to backstab again.\n");
	return 1;
  }	
   if(already_attacking(me,victim))
   {
      tell_object(me,"Backstab someone you're fighting?!\n");
      return 1;
   }
   

/*  OK, Gonna try add some chance for the victim to sense the backstab here.
    Idea is that it should be fairly hard to sense a backstab, and to protect
    mages and clerics somewhat I will include wis and int into the test so they
    get a higher chance of avoiding a backstab than a dumb fighter.  -Manshoon  */
    
    if(sense_check(me,victim))
    {
    	  tell_object(me,"Oh bugger, "+vname+" seems to have sensed your intentions!\n");
    }
    else 
    {   	  
      victim->adjust_hp(-damage,me);
      cost = me->query_level();
      me->adjust_gp(-cost);
      tell_object(victim,"You scream in pain as "+aname+" places a "+wname+
      			 " in your back!\nThat really did hurt!\n");
      
     tell_room(environment(me), vname+" screams in pain as "+aname+" places a"+
               wname+" in "+victim->query_possessive()+" back!\n",
               ({ me, victim }) );
  
     tell_object(me,vname+" makes a strange sound as you place a "+wname+" in "+
      		victim->query_possessive()+" back!\n");
	
      // Removed the bit that wrote out the damage done.....
   }
   victim->attack_by(me); 
   return 1;
}

string help(string str) {
  return
"Syntax: backstab <person>\n\n"
"Backstab is based on your level and dextirity. "
"Your victim has a chance of sensing the backstab and thus avoiding "
"it based on his level, wisdom and intelligence. "
"Wether you are successful or not, the victim will attack you.\n\n"
"You need a piercing weapon to be able to backstab and you must be hidden.\n"
"The cost is level dependent.\n\n"
"Example\n"
"> backstab merchant\n";
}

