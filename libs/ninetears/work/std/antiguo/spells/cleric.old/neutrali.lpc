/*** Neutralise Poison ***/
/*** -by Wonderflug ***/

#include "tweaks.h"

#define SP_NAME "Neutralise Poison"
#define GP NEUTRALISE_POISON_GP
#define LEVEL 2
#define LOCKOUT "cast"

string help()
{
  return
  "\n\n"
  "Spell Name: "+SP_NAME+"\n"
  "Sphere: Plant \n"
  "Level: "+LEVEL+"\n"
  "GP Cost: "+GP+"\n"
  "Description: \n"
  "This spell will cure the target of any maladies which happen to affect "
  "them.  Most notably, it will counteract the effect of Poison spells and "
  "other poisoned wounds.\n";
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
	write("Syntax: cast neutralise poison <target>\n");
	return 1;
  }
  if ( (int)my_caster->query_gp() < GP )
  {
	write("You don't have the energy to cast this spell.\n");
	return 1;
  }

  obs = find_match( str, environment(my_caster) );
  if (!(obs))
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
  object* obs;
  int i;

  tell_room(environment(caster), (string)caster->query_cap_name()+
	" chants, 'toxus wrathi aborum'.\n", caster);
  tell_object(caster, "You chant, 'toxus wrathi aborum'.\n");

  tell_room(environment(caster), (string)caster->query_cap_name()+
	" finishes the spell and "+target->query_cap_name()+
	" looks much better.\n", ({caster, target}));
  tell_object(target, caster->query_cap_name()+
	" finishes the spell with a gesture at you, and you \nstart to feel "
	"much much better as the poison leaves your body.\n");
  tell_object(caster, "You finish the spell and remove the poison "
	"from "+target->query_cap_name()+"'s body.\n");

  obs = all_inventory(target);
  for (i=0;i<sizeof(obs);i++)
	if ( (string)obs[i]->query_name() == "poisoned wound" )
  		obs[i]->dispell_me();
  return;
}
