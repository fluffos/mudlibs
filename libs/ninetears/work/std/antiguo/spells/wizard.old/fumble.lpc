
#include "tweaks.h"

#define SP_NAME "Fumble"
#define GP_COST FUMBLE_GP_COST
#define ALREADY_CASTING "cast"
#define save_type "spells"


object shadow;

void make_spell(object caster, object target);

string help() {
  return
	"\n\n"
	"Spell Name: "+SP_NAME+"\n"
	"School: Necromancy\n"
	"Level: 4th\n"
	"Gp Cost: "+GP_COST+"\n"
	"Description: \n"
	"  This spell causes the target to immediately fumble whatever is "
	"in their hand.  Depending on the skill of the caster, wielded "
	"weapons get either unwielded or dropped, and possibly other "
	"equipment as well.  Fast and experienced targets will not be "
	"affected as much.\n";
}

int cast_spell(string str, object caster)
{
  int cost;
  int i;
  object my_caster;
  object* target;
  object* ob;


  if (caster)
	my_caster = caster;
  else my_caster = this_player();

  if(interactive(my_caster))
  str = (string)my_caster->expand_nickname(str);

  if (my_caster->query_timed_property(ALREADY_CASTING))
  {
	write("You are already casting a spell.\n");
	return 1;
  }
  if ((int)my_caster->query_gp() < GP_COST )
  {
	write("You are too mentally drained to cast this spell.\n");
	return 1;
  }

  target = find_match( str, environment(my_caster) );

  if (sizeof(target)==0)
  {
	write("Your target is not here.\n");
	return 1;
  }

  if (interactive(caster) && (string)my_caster->query_guild_name() == "trickster" )
	cost = GP_COST/2;
  else 
	cost = GP_COST;

  write("You start to cast "+SP_NAME+".\n");
  say(my_caster->query_cap_name()+" begins to cast a spell.\n",
     previous_object());

  my_caster->add_timed_property(ALREADY_CASTING,3,1);
  my_caster->adjust_gp(-cost);
  call_out("make_spell",1,my_caster,target[0]);
  return 1;
}

void make_spell( object caster, object target )
{
  object* ob;
  object* ob2;
  int caster_level; 
  int target_level;
  int caster_int; 
  int target_dex;
  int caster_roll; 
  int target_roll;
  int i, j;

  say((string)caster->query_cap_name()+
	" chants, 'digitis mali failus'.\n", 
	caster);
  tell_object(caster, "You chant, 'digitus mali failus'.\n");

  /* do the effects and saving throw;  several possibilities; drop nothing, 
   * drop weapons, drop weapons and equip; this can be expanded easily by
   * putting more things in the switch...
   */

  caster_level = (int)caster->query_level();
  target_level = (int)target->query_level();
  caster_int = (int)caster->query_int();
  target_dex = (int)target->query_dex();

  caster_roll = random(FUMBLE_CASTER_ADJ*(caster_level+caster_int));
  target_roll = target_level+
		random(FUMBLE_TARGET_ADJ*(target_level+target_dex));

  if ( caster_roll > target_roll )
  {
    tell_object(target, caster->query_cap_name()+
	" completes his gestures, and you suddenly feel very clumsy, and"
	" can't hold on to your equipment.\n");
    tell_room(environment(target), caster->query_cap_name()+
      	" finishes a spell with a gesture at "+target->query_cap_name()+
	".\n", target);
  }
  else
  {
    tell_object(target, caster->query_cap_name()+
	" completes his gestures, pointing at you, but nothing happens.\n");
    tell_room(environment(target), caster->query_cap_name()+
	" finishes a spell with a gesture at "+target->query_cap_name()+
	", but nothing seems to happen.\n",target);
    return 1;
  }

  target->add_timed_property(ALREADY_CASTING,1,10);

/* kludge since drop_ob notifies the caster of items dropping, not the
 * the target.  no way around except to rewrite drop_ob HERE, which is
 * an even worse kludge, i think.  -- wonderflug
 */
  caster_roll = target_roll+10;

  switch( caster_roll - target_roll )
  {
	case 1..20:
	  ob = (object*)target->query_held_ob();
	  for (i=0;i<sizeof(ob);i++)
		if ( ob[i] )
	  		target->unhold_ob(ob[i]);
   	  break;
	default:
	  ob = all_inventory(target);
	  ob2 = (object*)target->query_worn_ob();
	  for (i=0;i<sizeof(ob);i++)
		if ( member_array(ob[i], ob2) == -1 )
		  target->drop_ob(ob[i]->query_name());
	  break;
  }

  return GP_COST;
}
