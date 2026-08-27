/******************
 * Dispell magic  *
 * -by Wonderflug *
 *****************/

#include "tweaks.h"

#define SP_NAME "Dispell Magic"
#define SPELLTYPE "
#define TYPE "magical"
#define save_type "spells"
#define GP DISPELL_MAGIC_GP
#define LEVEL 4
#define LOCKOUT "cast"

string help()
{
  return
  "\n\n"+
  "Spell Name: "+SP_NAME+"\n"+
  "School: Invocation\n"+
  "Level: "+LEVEL+"\n"+
  "GP Cost: "+GP+"\n"+
  "Description: \n"+
  "  This spell disrupts any enchantments that are upon the target.  "+
  "Higher level targets have enchantments (both good or bad) drawn to "+
  "them more strongly, and thus enchantments on them will be more difficult "+
  "to dispel.  A single dispel will only destroy one spell on the target, "+
  "and will only affect one target.  This spell will not affect inanimate "+
  "objects.\n";
}

int cast_spell(string str, object caster)
{

  object my_caster;
  object target;
  object* obs;
  int level;

  if (caster)
	my_caster = caster;
  else my_caster = this_player();

  if (!(str))
  {
	write("Syntax: cast dispel magic <target>\n");
	return 1;
  }
  if ( (int)my_caster->query_gp() < GP )
  {
	write("You don't have the energy to cast this spell.\n");
	return 1;
  }

  obs = find_match( str, environment(my_caster) );
  if (!(obs) || !sizeof(obs) )
  {
	write("Your target is not here.\n");
	return 1;
  }

  target = obs[0];
  if (!(find_living(target->query_name())))
  {
	write("This spell will not affect inanimate objects.\n");
	return 1;
  }

  level = (int)my_caster->query_level();
  if ( level < LEVEL*2 )
  {
	write("You are too low level to cast this spell.\n");
	return 1;
  }

  tell_object(my_caster,"You begin to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster), my_caster->query_cap_name()+
	" begins to cast a spell.\n", my_caster );

  my_caster->add_timed_property("cast",1,3);
  my_caster->adjust_gp(-GP);

  call_out("make_spell",1,my_caster,target);
  return 1;
}


void make_spell(object caster, object target)
{
  if ( (int)caster->query_int() < random((int)target->query_level()) )
  {
	tell_room(environment(caster), (string)caster->query_cap_name()+
	  " finishes the spell with a gesture at "+target->query_cap_name()+
	  ", \nbut nothing happens.\n", ({caster,target}));
	tell_object(caster,"You complete your spell, but realize that any "+
	  "enchantments on \n"+target->query_cap_name()+" were too powerful "+
	  "for your meager abilities.\n");
	tell_object(target,caster->query_cap_name()+
	  " finishes the spell with a gesture at you, but nothing \nseems to "+
	  "happen.\n");
	return;
  }

  tell_room(environment(caster), (string)caster->query_cap_name()+
	" finishes the spell with a flourish.\n", ({caster, target}));
  tell_object(target, caster->query_cap_name()+
	" finishes the spell with a gesture at you.\n");
  tell_object(caster, "You finish the spell and destroy the magic "+
	"around "+target->query_cap_name()+".\n");

  target->dispell_me();
  return;
}
