/*** Template Spell ***/
/*** By Wonderflug ***/

#include "spells.h"
inherit BASES+"patch";
inherit BASES+"tipos";

#define SP_NAME "Template"
#define SPHERE "womble"
#define LEVEL 1
#define GP_COST LEVEL*2
#define TYPE "laughter"

/* help function */
string help() 
{
  return "\n\n"
    "Spell Name: " SP_NAME "\n"
    "Sphere: " SPHERE "\n"
    "Level: "+LEVEL+"\n"
    "Gp Cost: "+GP_COST+"\n"
    "Damage Type: " TYPE "\n"
    "Description: \n"
    "  This spell is buggy.  The creator who made it is an idiot and "
    "forgot to customize the help file.  Laugh at them real hard.\n\n";
}

/* Prototype */
mixed spell(string str, object caster, int cast);

/* If this is cast by an NPC, cast will be the NPC casting it.  Otherwise
 * it will be 0.
 * str is the argument string, ie, targets as typed by the player.
 */
int cast_spell(string str, object cast)
{
  mixed ret;
  object caster;

  if(cast) 
    caster = cast;
  else 
  {
    /* The caster is a player, and the target string may contain nicknames
     * which need expansion to their definitions prior to using them.
     */
    caster = this_player();
    str = caster->expand_nickname(str);
  }

  /* Cast the spell.  Will return a string if there's an error; otherwise
   * assume success.  Note we call with a 1 to indicate the spell is being
   * cast.  This way creators can do the same call with a 0 and have the
   * messages/gp requirements suppressed.
   */
  ret = spell(str, caster, 1);
  if (stringp(ret))
  {
	 notify_fail(ret);
	 return 0;
  }

  tell_object(caster,"You start to cast " SP_NAME ".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast "
	"a spell.\n", caster);
  return 1;
}

/* This is just for convenience.  Checks that should be done each
 * round of casting/in multiple places should go in this function.
 */
mixed do_checks(string str, object caster, int cast)
{
  /* Find the targets.  Note that this should be repeated on each stage
   * of the spell, if the effects are not instantaneous.  Some of course
   * may only need to check targets at the end. (eg a spell hitting everything
   * in the room)  At any rate, delete one of these before use :)
   */

  /* This is the first way.  A single target. */
  ob = find_one_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "You don't see your target here.\n";

  /* This is the second way.  Multiple targets.  */
  ob = find_unique_match(str, environment(caster));
  if ( !sizeof(ob) || !ob )
    return "You don't see your target here.";

  /* Check if targets are living here. */

  /* Check they have enough gp still.  This also must be done each
   * round of casting.  We don't deduct GP til later though.
   * Note if we have sphere based GP cost this check is inaccurate.
   */
  if (cast && (int)caster->query_gp() < GP_COST )
    return "You lack the power to cast this spell.\n";
  else caster->adjust_gp(-GP_COST);

  return ob;
}

mixed spell(string str, object caster, int cast)
{
  mixed ob;

  /* Can only cast one spell from a given sphere/school at a time */
  if ((int)caster->query_spell_effect(SPHERE))
    return "You are already casting a " SPHERE " spell.\n";
  
  /* Do error checks; if we don't get a string we get the objects */
  if ( stringp( ob=do_checks(str, caster, cast) ) )
    return ob;

  /* Do the spell effects here and delete the following lines, or add
   * a casting delay and modify the following lines.  
   */
  caster->add_spell_effect(number of rounds to cast, SPHERE, SP_NAME,
    this_object(), "hb_spell", ({ str, cast, ob, any other params you need }));
  return 1;
}

/* If using add_spell_effect, this function will get called each round
 * for the number of rounds you specified.  caster is the object casting the
 * spell; params is that last parameter you passed to add_spell_effect
 * exactly how you passed it, and time is the number of rounds remaining
 * in the effect.  eg, if we specified 3 in add_spell_effect, this would
 * get called successively with 3, 2, and 1 as the third parameter.
 * NOTE: Always return low numbers (preferably zero) from these spell
 * heartbeats-- the return value gets added to the player as xp.
 */
int hb_spell(object caster, mixed *params, int time)
{
  mixed ob;
  int cost;

  /* Add/delete from this as necessary. Note we only do tell_room's if 
   * the spell was cast, ie, params[1] is nonzero 
   */
  switch( time )
  {
    case 4:
      if ( stringp( ob=do_checks(params[0], caster, params[1]) ) )
      {
        tell_object(caster, ob);
        if ( params[1] )
          tell_room(environment(caster), caster->query_cap_name()+" stops casting.\n",
            caster);
      }
      /* effects (messages) during 1st round of casting */
      return 0;

    case 3:
      if ( stringp( ob=do_checks(params[0], caster, params[1]) ) )
      {
        tell_object(caster, ob);
        if ( params[1] )
          tell_room(environment(caster), caster->query_cap_name()+" stops casting.\n",
            caster);
      }
      /* effects (messages) during 2nd round of casting */
      return 0;

    case 2:
      if ( stringp( ob=do_checks(params[0], caster, params[1]) ) )
      {
        tell_object(caster, ob);
        if ( params[1] )
          tell_room(environment(caster), caster->query_cap_name()+" stops casting.\n",
            caster);
      }
      /* effects (messages) during 3rd round of casting */
      return 0;

    default:
      break;
  }
  if ( stringp( ob=do_checks(params[0], caster, params[1]) ) )
  {
    tell_object(caster, ob);
    tell_room(environment(caster), caster->query_cap_name()+" stops casting.\n",
      caster);
  }

  /* may want to alter below, based on sphere; if so
   * move the check to after the sphere code
   */
  cost = GP_COST; 
  if ( params[1] && caster->adjust_gp(-cost) < 0 )
  {
    tell_object(caster, "You are too exhausted to complete the spell.\n");
    tell_room(environment(caster, caster->query_cap_name()+
      " stops casting.\n", caster);
  }

  /* Effects of the spell go here.  At this point, params[0] is the 
   * original target string, params[1] is whether it was cast as a spell
   * or not, params[2] is the original matched targets, further params
   * are as you added to the add_spell_effects call; ob contains the targets
   * currently in the room.  Yes, 3 sets of effects for different sphere
   * powers.
   */
  switch( caster->query_sphere_power(SPHERE) )
  {
    case "minor":
      break;
    case "major":
      break;
    default:
      break;
  }

  if ( params[1] )   /* if cast as a spell */
  {
    /* Any casting specific messages go here. */
  }

  /* Noncasting specific messages go here. */

  return 0;
}
