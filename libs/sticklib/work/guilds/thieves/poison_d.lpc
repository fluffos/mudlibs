/* Poison daemon -- Coded by: Colt -- Feb 4, 1996 --  
   New features			Skarda  Nov 13, 1996

   Handles poisonings, mainly used for new thief skill of poison.
   Poison strengths should be on a scale of 0 - 100 for the most part.
   100 being the strongest, 0 being useless.  Higher than 100 is
   possible but don't go too far past.
   Possible extra effects:    (Any other ideas?)
     Blindness         (strength > 20)
     Hallucinations    (strength > 40)
     Panic             (strength > 60)
     Paralysis         (strength > 80)
   Extra effects happen based on strength of the poison.  For
   the thief skill, strength of poison is based on their skill
   in making poisons. (More about skill in the skill file itself).
*/

// 11-Oct-97 / Graah: Healers must not be poisoned.

#include <conditions.h>
#include <attack.h>
#include <guild.h>

mixed *query_poisoned_things(status objects);
status remove_poisoned_living(object who, int silently);
status remove_poisoned_thing(object what);
void extra_affect(object who);
mapping p_things,p_livings;

/* Function: varargs status
	     add_poisoned_thing(object what, int p_strength,int uses)

   Use:
       When a thing becomes poisoned, use this function to notify
       the daemon.

   Arguments:
     1: object what - the object being poisoned.
     2: int p_strength - strength of poison being applied (see above)
     3: int uses - Number of times poison can be used before 
		   it wears off.  If this value is not supplied
		   one will be automatically chosen based on
		   poison strength

   Returns: 
      Function returns 1 upon success.
*/
varargs status 
add_poisoned_thing(object what,int p_strength,int uses)
{
    string dummy;
    if (!p_things)
	p_things = ([]);
    if (!uses)
	uses = 4 + (random(p_strength/10));
    remove_poisoned_thing(what);
    p_things += ([ what : p_strength; uses ]);
    if (sscanf((string)what->query_short(),"%s covered in a strange substance",dummy) != 1)
    {
	if (what->is_wielded())
	    sscanf(what->query_short(), "%s (wielded)",dummy);
	else
	    dummy = what->query_short();
	what->set_short(dummy+" covered in a strange substance");
    }
    return 1;
}
/* Function: status
	     remove_poisoned_thing(object what)

   Use:
      Removes a poisoned thing from the mapping.

   Arguements:
      1: object what - The object to be removed.

   Returns:
      1 for success.
      0 if thing wasn't even poisoned or failed.
*/
status 
remove_poisoned_thing(object what)
{
    string desc;
    string dummy;
    if (member(query_poisoned_things(1), what) == -1)
	return 0;        // Not poisoned
    if (sscanf((string)what->query_short(),"%s covered in a strange substance",desc) == 1)
	what->set_short(desc);
    m_delete(p_things,what);
    return 1;
}
/*
   Function: status
	     poisoned_thing_used(object what)
   Use:
      Subtracts 1 use from poisoned item.  Done automatically
      when a player is poisoned.  So, no need to call this unless
      you want extra uses removed.

   Arguements:
      1: object what - object of thing being used.

   Returns:
      1 for success.
*/
status 
poisoned_thing_used(object what)
{
    p_things[what,1] -= 1;
    if (p_things[what,1] <= 0)
	remove_poisoned_thing(what);
    return 1;
}
/* Function: varargs status
	     add_poisoned_living(object who, object with_what)
   Use:
      Call this when a hit(or whatever) delivers poison to a victim.
      Can be used with monsters who poison.
      Note: This function will remove 1 use from poisoned 
	    thing.

   Arguements:
      1: object who - object being poisoned.
      2: object with_what - non-living thing or living(usually a 
			    monster) that poisons
      3: int p_strength - used when arg 2 is a living, sets
			  poison strength.  Not needed when
			  poison is deliverd through a "thing".
   Returns:
     1 for success.
     0 if no victim, no thing/living, or weapon isn't poisoned.
*/
varargs status 
add_poisoned_living(object who,object with_what, int p_strength)
{
    if (!who || !with_what)
	return 0;
    if (!p_things) p_things = ([]);
    if (!living(with_what))
    {   
	if(member(query_poisoned_things(1), with_what) == -1)
	    return 0;
	else
	{   
	    p_strength = p_things[with_what,0];
	    poisoned_thing_used(with_what);
	}
    }
    if (!p_livings || !m_sizeof(p_livings))
    {   
	p_livings = ([]);
	remove_call_out("poison_effects"); 
	call_out("poison_effects",5); //Something poisoned, start calls
    }
#ifdef GN_HEALER
    if (who->query_guild() != GN_HEALER)
	p_livings += ([ who : p_strength; time() ]);
#endif

return 1;
}
/* Function: status
	 remove_poisoned_living(object who,int silently)

Use:
  Remove a poisoned living from mapping...Normally done
  automatically but in case of antidote? or something
  use this.

Arguements:
  1:  object who - object to be removed
  2:  int silently - 1 to do it silently
Returns:
  1 for success.
*/
status 
remove_poisoned_living(object who,int silently)
{
    if (!silently)
	who->tell_me("You feel the poison wear off.");
    m_delete(p_livings,who);
    return 1;
}
/* Function: void
	     clean_maps()
   Use:
      Cleans out non-existing livings, weapons, and livings
      poison has worn off on.  No need to ever call this.
   Arguements:
      none.
   returns: none.
*/

void 
clean_maps()
{
    int i,p_strength,p_started;
    object *ppl;

    m_delete(p_things,0);
    m_delete(p_livings,0);
    ppl = m_indices(p_livings);
    for(i=0;i < sizeof(ppl);i++)
    {
	if (ppl[i]->is_ghost())
	    remove_poisoned_living(ppl[i],0);
	p_started = p_livings[ppl[i],1];
	p_strength = p_livings[ppl[i],0];
	if ((time() - p_started) >= (2*p_strength/3)) 
	    remove_poisoned_living(ppl[i],0);
    }
}
/* Function: void
	     poison_effects()
   Use:
     Cycles through all poisoned livings.  Gives messages and 
     dmg.  Don't call this.
   Arguements: none.
   Returns: none.
*/
void 
poison_effects()
{
    object *ppl;
    string p_msg, *p_mesg;
    int i,p_strength;
    int dmg;

    clean_maps();
    ppl = m_indices(p_livings);
    for (i=0;i < sizeof(ppl);i++)
    {
	if (ppl[i]->is_ghost() ||
	  ppl[i]->query_dead()
#ifdef GN_HEALER
	  || ((string)ppl[i]->query_guild() == GN_HEALER)
#endif
	)
	    remove_poisoned_living(ppl[i],0);
	else
	{
	    p_msg = ({
	      "You shiver uncontrollably from the poison.#"+
	      ppl[i]->query_name() + " shivers uncontrollably.",

	      "Poison causes your stomach to wrench painfully.#"+
	      ppl[i]->query_name() + " clenches " + 
	      ppl[i]->query_possessive() + " stomach and " +
	      " grimaces in pain.",

	      "The poison makes you sweat from every pore in " + 
	      " your body.#"+ ppl[i]->query_name()+
	      " is sweating profusely.",

	      "Your insides feel like they are on fire from the poison.#"+
	      ppl[i]->query_name() + " moans from some internal agony.",

	    })[random(4)];
	    p_mesg = explode(p_msg,"#");
	    ppl[i]->tell_me(p_mesg[0]);
	    environment(ppl[i])->tell_here(p_mesg[1],ppl[i]);
	    p_strength = p_livings[ppl[i],0];
	    // Dmg done here
	    dmg = ((p_strength/5)+random(p_strength/4));
	    ppl[i]->hit_player(dmg,DT_POISON,0, this_object());
	    // specials done here
	    if (random(p_strength) >= (25 + random(200)))
		extra_affect(ppl[i]);
	}
    }
    // If no one poisoned don't call_out
    if (sizeof(ppl) > 0)
	call_out("poison_effects",random(5));
}
/* Function: void
	     extra_affect(object who)
   Use:
      Does extra special stuff. (see above) Don't call this.
   Arguements: none.
   Returns: none.
*/
void 
extra_affect(object who)
{
    int p_strength;
    p_strength = p_livings[who,0];
    if (random(p_strength) > 90)
    {
	who->tell_me("Your muscles clench as poison takes its \
course.\nYou can't move!");
	environment(who)->tell_here(who->query_name() + 
	  "'s body clenches and stops moving...",who);
	who->set_condition(C_STUNNED,random(p_strength/24));
    }
    else
    if (random(p_strength) > 80)
    {
	who->tell_me("You suddenly feel very afraid...\n\
You run in PANIC!");
	environment(who)->tell_here(who->query_name() +
	  " turns white with fear and flees.",who);
	who->run_away();
    }
    else
    if (random(p_strength) > 40)
    {
	who->tell_me("Images cloud your thinking.");
	environment(who)->tell_here(who->query_name() +
	  " lashes out at things only " +
	  who->query_pronoun() + " can see!",who);
	who->set_condition(C_HALLUCINATING,random(p_strength/12));
    }
    else
    if (random(p_strength) > 80)
    {
	who->tell_me("Your eyes burn.\nYou are \
BLIND!");
	environment(who)->tell_here(who->query_name() +
	  " claws at " + who->query_possessive() +
	  " eyes and stumbles around in blindness.",who);
	who->set_condition(C_BLIND,random(p_strength/24));
    }
}
/* Function: mixed *
	     query_poisoned_things(status objects)
   Use:
     Tells what things are poisoned.
   Arguements:
     1: status objects - 1 to return the actual objects
			 0 to return thing names
   Returns:
     An array of either actual objects or things names.
*/
mixed *
query_poisoned_things(status objects)
{
    object *things;
    string *names;
    int i;
    names = ({});
    things = m_indices(p_things);
    if (objects)
	return things;
    for(i=0;i < sizeof(things);i++)
	names += ({ things[i]->query_name() });
    return names;   
}

/* Function: mixed *
	     query_poisoned_livings(status objects)
   Use:
      Returns living players.
   Arguements:
     1: status objects -- 1 to return actual objects
			  0 to return living names
   Returns:
     An array of either objects or names.
*/
mixed *
query_poisoned_livings(status objects)
{
    object *who;
    string *names;
    int i;
    names = ({});
    who = m_indices(p_livings);
    if (objects)
	return who;
    for(i=0;i < sizeof(who);i++)
	names += ({ who[i]->query_real_name() });
    return names;
}
/* Function: status
	     is_poisoned(object who)

   Use: 
     Can be used to find if a specific living is poisoned.
   Arguements:
     1: object who - object you are checking for poison
   Returns:
      1 if object is poisoned
      0 if object is not poisoned
*/
status
is_poisoned(object who)
{
    object *ppl;

    ppl = query_poisoned_livings(1);
    if (member(ppl, who) != -1)
	return 1;
    else
	return 0;
}



void
create()
{
    p_livings = ([ ]);
}
