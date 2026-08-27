/*** MIRROR IMAGE ***/
/*** NPC friendly, coded by Wonderflug ***/

#include "tweaks.h"

#define SP_NAME "Mirror Image"
#define GP_COST MIRROR_GP
#define ALREADY_CASTING "cast"

object shadow;

void make_spell(object caster, object target);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Conjuration\n"
       "Level: 4th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "  This spell creates several mirror images of the target that "
       "surround them.  These images are indistinguishable from the "
       "target, and often attackers will be confused as to which one the "
       "real target is.  When a clone is hit, it is destroyed.  The number "
       "of clones created is dependent on the caster's level.  Smart "
       "and experienced attackers may see through the images straight to "
       "target, however.\n\n";
}

int cast_spell(string str, object caster)
{
  int i;
  object* obs;
  object target, my_caster;

  if (caster)
	my_caster = caster;
  else 
  {
	my_caster = this_player();
	str = (string)my_caster->expand_nickname(str);
  }


  if (my_caster->query_timed_property(ALREADY_CASTING))
  {
	tell_object(my_caster,"You are already casting a spell.\n");
	return 1;
  }
  if ((int)my_caster->query_gp() < GP_COST )
  {
	tell_object(my_caster,"You are too mentally drained to cast "
	  "this spell.\n");
	return 1;
  }

  obs = find_match( str, environment(my_caster) );
   if(!sizeof(obs))
  {
	tell_object(my_caster, "There is nobody of that name here.\n");
	return 1;
  }
  target = obs[0];

  if ( target->query_mirror_spell() )
  {
	tell_object(my_caster,"Your target already has mirror images.\n");
	return 1;
  }

  tell_object(my_caster, "You start to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster), my_caster->query_cap_name()+
	" begins to cast a spell.\n",
        my_caster);

  my_caster->add_timed_property(ALREADY_CASTING,3,1);
  my_caster->adjust_gp(-GP_COST);
  call_out("make_spell",1,my_caster,target);
  return 1;
}

void make_spell( object caster, object target )
{
  int num_images;

  num_images = (int)caster->query_level() / MIRROR_IMAGES_PER_LEVEL;

  tell_room(environment(caster), caster->query_cap_name()+
	" chants, 'sancti numbro duplis'.\n", 
	caster);
    
  tell_object(caster, "You chant, 'sancti numbro duplis'.\n\nYou make "+
	num_images+" clones of "+target->query_cap_name()+" appear.\n");
  tell_object(target, caster->query_cap_name()+" casts a spell on you, "
	"and "+num_images+" mirror images of you appear and \narray "
	"themselves around you.\n");
  tell_room(environment(caster), caster->query_cap_name()+
        " finishes a spell, and "+num_images+" duplicates of "+
	target->query_cap_name()+" \nsuddenly appear.\n",
        ({ target, caster }) ); 

  shadow = clone_object(MIRROR_SHADOW);
  shadow->setup_shadow(target,num_images); 
  target->add_extra_look(shadow);

  return GP_COST;
}

