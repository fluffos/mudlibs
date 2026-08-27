/*** Stoneskin ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define SP_NAME "Stoneskin"
#define GP_COST STONESKIN_GP
#define ALREADY_CASTING "cast"

object shadow;

void make_spell(object caster, object target);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: \n"
       "Level: 4th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "  This spell causes the target's skin become very stone-like. "
       "Damage from attacks will be greatly reduced while the stoneskin "
       "is in effect, but due to its cumbersome nature the target's "
       "movements and reactions will slow down, lowering dexterity somewhat. "
       "The spell lasts 1 round per level of the caster.\n\n";
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
  if (!(obs))
  {
        tell_object(my_caster, "There is nobody of that name here.\n");
        return 1;
  }
  target = obs[0];

  if ( target->query_stoneskin_spell() || target->query_mirror_spell() ||
        target->query_armour_spell() || target->query_wraithform() )

  {
        tell_object(my_caster,"Magic around your target disrupts your "
          "spell.\n");
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
  tell_room(environment(caster), caster->query_cap_name()+
        " chants, 'amani stohrikus'.\n",
        caster);

  tell_object(caster, "You chant, 'amoris stohrikus'.\n\nYou make "+
        target->query_cap_name()+"'s skin harden considerably.\n");
  tell_object(target, caster->query_cap_name()+" casts a spell on you, "
	"and you feel your skin harden considerably.\nYou feel "
        "much slower, and very protected.\n");
  tell_room(environment(caster), caster->query_cap_name()+
        " finishes a spell, and "+target->query_cap_name()+
        "'s skin suddenly hardens into a \nstonelike shell.\n",
        ({ target, caster }) );

  target->add_timed_property("stoneskin_on",1,
	STONESKIN_DURATION_BASE+(STONESKIN_DURATION_LEVELX*(int)caster->query_level()) );
  target->adjust_tmp_dex(-2);

  shadow = clone_object(STONESKIN_SHADOW);
  shadow->setup_shadow(target);
  target->add_extra_look(shadow);

  return GP_COST;
}

