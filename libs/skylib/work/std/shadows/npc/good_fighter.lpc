/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: good_fighter.c,v 1.16 2000/03/28 21:19:21 ceres Exp $
 * $Log: good_fighter.c,v $
 * Revision 1.16  2000/03/28 21:19:21  ceres
 * Varioius tweaks
 *
 * Revision 1.14  1999/02/16 02:23:04  sin
 * Fixed bug with giving him strike and crush
 *
 * Revision 1.13  1999/01/15 17:26:04  presto
 * Added '- ({ 0 })' to the assignment of 'holding' around line 451
 *
 * Revision 1.12  1999/01/15 17:22:10  ceres
 *  Forcibly unlocked by presto
 *
 * Revision 1.11  1999/01/05 03:03:24  sin
 * Turned off debugging.
 *
 * Revision 1.10  1998/12/31 20:02:48  ceres
 * Fixed error with command (had extraneous players name), added debug info, fixed inversion of query_special_manoeuvre()
 *
 * Revision 1.9  1998/12/31 01:01:19  ceres
 * Made disarm a little rarer since it shouldn't be used as often as say slash or crush.
 *
 * Revision 1.8  1998/09/10 20:20:27  ceres
 * Fixed riposte error.
 *
 * Revision 1.7  1998/04/12 21:33:14  sin
 * Added Ceres' new crush command to the good fighter effect.
 *
 * Revision 1.6  1998/04/12 00:09:05  sin
 * Hehhehe.  forgot one piece of SUPPORT_PIERCE deadwood.
 *
 * Revision 1.5  1998/04/12 00:07:52  sin
 * Added support for USE_UNARMED and got rid of some dead wood from the
 * changeover.
 *
 * Revision 1.4  1998/02/08 21:36:20  sin
 * activated change for new skill tree.
 *
 * Revision 1.3  1998/02/06 22:18:29  sin
 * Change in preparation for the skills rearrange.c
 *
 * Revision 1.2  1998/01/30 10:50:45  sin
 * Had to rearrange fight_in_progress() slightly to make the chaining work.
 *
 * Revision 1.1  1998/01/06 04:39:52  ceres
 * Initial revision
 * 
*/
/**
 * The Good Fighter shadow.  The main docs are stored in the effect
 * header file, not here...  Mostly for standardisation reasons.
 *
 * @see /std/effects/npc/good_fighter
 *
 * @author Sin
 * @created 12 November 1997
 * @changed 13 November 1997 -- Sin
 *     Converted it from a pure shadow to a shadow/effect pair
 * @changed 11 April 1998 -- Sin
 *     Added support for USE_UNARMED.
 *     God rid of some dead wood.
 * @changed 12 April 1998 -- Sin
 *     Added support for crush
 */

#include <good_fighter.h>

#define LOGFILE "good_fighter"
#define CMDS "/cmds/guild-race/fighting/"

#define DEBUG

inherit "/std/effect_shadow";

string *specials;
int bluntorsharp;
int dodgeorparry;
object victim;

/**
 * @ignore
 * Used only to insure that the specials array is actually an array at
 * all times.
 */
void create()
{
  specials = ({ });
}

/**
 * This is a helper function used by the good_fighter_setup() function to
 * ensure that the specified skill is at least at a particular level.
 *
 * @param skill The skill to check
 *
 * @param level The minimum acceptable level for this skill
 */
protected void check_skill(string skill, int level)
{
  int cur;

  cur = player->query_skill(skill);
  if (cur < level)
    player->add_skill_level(skill, level - cur);
}

/**
 * This helper function is used by good_fighter_setup() to add a known
 * command to the NPC's repertoire _only_ if the relevant skill is above
 * a certain level.  If the command is added, then it is also stored in the
 * specials[] array for later use by fight_in_progress()
 *
 * @param command The command to be added
 *
 * @param skill The skill that controls the NPC's effectiveness with this
 * command.
 *
 * @param level The minimum level before the command can be added.
 */
protected void check_add_command(string command, string skill, int level)
{
  int cur;

  cur = player->query_skill(skill);
  if (cur >= level) {
    player->add_known_command(command);
    specials += ({ command });
  }
}

/**
 * This function is called from a callout() registered when setup_shadow()
 * is called.  It is responsible for ensuring that all of the NPC's skills
 * are at a reasonable level, that the NPC has the commands appropriate
 * for its priorities and level, and that the tactics are set appropriately.
 */
void good_fighter_setup()
{
  int adjust;
  int lvl;
  int *args = arg();

  if (!args || !arrayp(args) || sizeof(args) != 2)
    return;

  specials = ({ });
  bluntorsharp = args[0];
  dodgeorparry = args[1];

  lvl = player->query_level();
  check_skill("other.perception", lvl / 2);
  check_skill("other.health", lvl);
  adjust = lvl * 3 / 4;
  if (bluntorsharp == USE_PIERCE) {
    check_skill("fighting.combat.melee.blunt", lvl - adjust);
    check_skill("fighting.combat.melee.sharp", lvl - adjust);
    check_skill("fighting.combat.melee.pierce", lvl + adjust);
    check_skill("fighting.combat.melee.unarmed", lvl - adjust);
  } else if (bluntorsharp == USE_BLUNT) {
    check_skill("fighting.combat.melee.blunt", lvl + adjust);
    check_skill("fighting.combat.melee.sharp", lvl - adjust);
    check_skill("fighting.combat.melee.pierce", lvl - adjust);
    check_skill("fighting.combat.melee.unarmed", lvl - adjust);
  } else if (bluntorsharp == USE_SHARP) {
    check_skill("fighting.combat.melee.blunt", lvl - adjust);
    check_skill("fighting.combat.melee.sharp", lvl + adjust);
    check_skill("fighting.combat.melee.pierce", lvl - adjust);
    check_skill("fighting.combat.melee.unarmed", lvl - adjust);
  } else if (bluntorsharp == USE_UNARMED) {
    check_skill("fighting.combat.melee.blunt", lvl - adjust);
    check_skill("fighting.combat.melee.sharp", lvl - adjust);
    check_skill("fighting.combat.melee.pierce", lvl - adjust);
    check_skill("fighting.combat.melee.unarmed", lvl + adjust);
  } else {
    check_skill("fighting.combat.melee.blunt", lvl);
    check_skill("fighting.combat.melee.sharp", lvl);
    check_skill("fighting.combat.melee.pierce", lvl);
    check_skill("fighting.combat.melee.unarmed", lvl);
  }

  adjust = lvl * 2 / 3;
  if (dodgeorparry == DEFEND_DODGE) {
    check_skill("fighting.combat.dodging", lvl + adjust);
    check_skill("fighting.combat.parry", lvl - adjust);
    player->init_command("tactics response dodge", 1);
  } else if (dodgeorparry == DEFEND_PARRY) {
    check_skill("fighting.combat.dodging", lvl - adjust);
    check_skill("fighting.combat.parry", lvl + adjust);
    player->init_command("tactics response parry", 1);
  } else {
    check_skill("fighting.combat.dodging", lvl);
    check_skill("fighting.combat.parry", lvl);
    player->init_command("tactics response neutral", 1);
  }
  check_skill("fighting.combat.special", lvl / 2);
  check_skill("fighting.points", lvl * 2);

  player->init_command("tactics attitude offensive", 1);

  if (bluntorsharp != USE_BLUNT) {
    if (dodgeorparry == DEFEND_PARRY)
      check_add_command("riposte", "fighting.combat.special", 15);
    check_add_command("hack", "fighting.combat.special", 15);
    check_add_command("slash", "fighting.combat.special", 15);
    if (bluntorsharp == USE_PIERCE)
      check_add_command("impale", "fighting.combat.special", 50);
  }
  if (bluntorsharp == USE_BLUNT || bluntorsharp == USE_BALANCED) {
    check_add_command("strike", "fighting.combat.special", 15);
    check_add_command("crush", "fighting.combat.special", 50);
  }
  check_add_command("disarm", "fighting.combat.parry.melee", 100);
  check_add_command("kick", "fighting.combat.special", 15);
  check_add_command("punch", "fighting.combat.special", 15);
  player->add_known_command("concentrate");
}

/**
 * This helper function is used by fight_in_progress() to see if one of
 * the NPC's weapons are appropriate for use with the 'crush' command.
 *
 * @param weapon The object to check.
 *
 * @return 1 if the object is appropriate, 0 otherwise
 */
protected int check_crush(object weapon)
{
  return (CMDS "crush")->check_blunt(weapon);
}

/**
 * This helper function is used by fight_in_progress() to see if one of
 * the NPC's weapons are appropriate for use with the 'riposte' command.
 *
 * @param weapon The object to check.
 *
 * @return 1 if the object is appropriate, 0 otherwise
 */
protected int check_riposte(object weapon)
{
  return (CMDS "riposte")->check_pierce(weapon);
}

/**
 * This helper function is used by fight_in_progress() to see if one
 * of the NPC's weapons are appropriate for use with the 'strike' command.
 *
 * @param weapon The object to check.
 *
 * @return 1 if the object is appropriate, 0 otherwise
 */
protected int check_strike(object weapon)
{
  return (CMDS "strike")->check_blunt(weapon);
}

/**
 * This helper function is used by fight_in_progress() to see if one
 * of the NPC's weapons are appropriate for use with the 'hack' command.
 *
 * @param weapon The object to check.
 *
 * @return 1 if the object is appropriate, 0 otherwise
 */
protected int check_hack(object weapon)
{
  /* This code is copied out of the hack command, since it isn't
   * conveniently bundled in a separate function like the strike
   * and riposte commands are. */
  if(!weapon)
    return 0;
  
  if (weapon->query_weapon_type() &&
      member_array(weapon->query_weapon_type(), ({ "sword", "axe" })) != -1)
    return 1;
  if (weapon->id("sword"))
    return 1;
  if (weapon->id("blade"))
    return 1;
  if (weapon->id("cutlass"))
    return 1;
  if (weapon->id("sabre"))
    return 1;
  if (weapon->id("foil"))
    return 1;
  if (weapon->id("katana"))
    return 1;
  if (weapon->id("kring"))
    return 1;
  if (weapon->id("rapier"))
    return 1;
  if (weapon->id("sarilak"))
    return 1;
  if (weapon->id("ninjan-to"))
    return 1;
  if (weapon->id("tan-to"))
    return 1;
  if (weapon->id("waki-zashi"))
    return 1;
  if (weapon->id("scimitar"))
    return 1;
  if (weapon->id("axe"))
    return 1;
  return 0;
}

/**
 * This helper function is used by fight_in_progress() to see if one
 * of the NPC's weapons are appropriate for use with the 'impale' command.
 *
 * @param weapon The object to check.
 *
 * @return 1 if the object is appropriate, 0 otherwise
 */
protected int check_impale(object weapon)
{
  return (CMDS "impale")->check_pierce(weapon);
}

/**
 * This helper function is used by fight_in_progress() to see if one
 * of the NPC's weapons are appropriate for use with the 'slash' command.
 *
 * @param weapon The object to check.
 *
 * @return 1 if the object is appropriate, 0 otherwise
 */
protected int check_slash(object weapon)
{
  /* This code is copied out of the slash command, since it isn't
   * conveniently bundled in a separate function like the strike
   * and riposte commands are. */
  if (member_array(weapon->query_weapon_type(), ({ "sword", "knife" })) != -1)
    return 1;
  if (weapon->id("knife"))
    return 1;
  if (weapon->id("dagger"))
    return 1;
  if (weapon->id("sword"))
    return 1;
  if (weapon->id("blade"))
    return 1;
  if (weapon->id("cutlass"))
    return 1;
  if (weapon->id("sabre"))
    return 1;
  if (weapon->id("foil"))
    return 1;
  if (weapon->id("katana"))
    return 1;
  if (weapon->id("kring"))
    return 1;
  if (weapon->id("rapier"))
    return 1;
  if (weapon->id("sarilak"))
    return 1;
  if (weapon->id("ninjan-to"))
    return 1;
  if (weapon->id("tan-to"))
    return 1;
  if (weapon->id("waki-zashi"))
    return 1;
  if (weapon->id("scimitar"))
    return 1;
  return 0;
}

/**
 * This function is called once per combat round by the combat shadow,
 * and does most of the work for this shadow.  It controls on whom
 * the NPC is concentrating, chooses an appropriate attack, and chooses
 * an appropriate weapon for the attack.
 *
 * <p>Most of the intelligence is in the specific choice of attack, and
 * there isn't a whole lot in that.  It restricts itself to simply going
 * through the attacks stored in the specials[] array (calculated in
 * the call to good_fighter_setup()), finding which attacks are valid (based
 * on whether the opponent is holding a weapon and which weapons are wielded
 * by the NPC).  Once it has a list of valid commands, it choses from them
 * randomly.
 * 
 * <p>Regardless, there is always the possibility that this function will
 * drop through and allow the combat handler to attack normally.  That
 * chance is inversely proportional to the NPC's level.
 *
 * @param attacker The current person attacking the NPC.
 */
void fight_in_progress(object attacker)
{
  object ts, temp;
  int chance;
  string cmd;

  /* I have to get to the top of the shadow stack, because the combat
   * shadow was probably added after this one. */
  ts = player;
  while ((temp = shadow(ts, 0)) != 0 && temp != ts)
    ts = temp;

  if (victim && !objectp(victim))
    victim = 0;
  if (victim && !interactive(victim))
    victim = 0;
  if (victim && environment(victim) != environment(player))
    victim = 0;
  if (victim && victim != attacker)
    return;
  if (!victim) {
    ts->concentrate(attacker->query_short());
    victim = ts->query_concentrating();
    if (!victim)
      return;
  }
  if (!ts->query_special_manoeuvre() ||
      (sizeof((int *)ts->effects_matching("fighting.combat.special")))) {
    player->fight_in_progress(attacker);
#ifdef DEBUG
    event(environment(player), "inform", "Already doing special", "combat");
#endif
    return;
  }

  /*
   * As the NPC gets higher level, there should be more possiblity of
   * it using a special command.  But on the other hand, it mustn't
   * ever get to the point that it will _always_ use special commands.
   * I have fixed the upper limit at a 90% chance of using a special
   * command, and that is reached at level 300.
   * Right now the probability curve is linear.  It should really
   * be a sigmoid.
   */
  chance = ts->query_level();
  if (chance > 300)
    chance = 90;
  else
    chance = (chance * 13) / 60;
  chance += 15;
  if (random(100) + 1 < chance) {
    object *holding;
    string *candidates;
    int i, j;

    candidates = ({ });
    holding = player->query_holding() - ({ 0 });

    for (i = 0; i < sizeof(specials); i++) {
      switch (specials[i]) {
      case "crush":
        /* syntax: crush <person> with <weapon> */
        for (j = 0; j < sizeof(holding) && !check_crush(holding[j]); j++);
        if (j < sizeof(holding))
          candidates += ({ "crush " + victim->query_name() +
            " with " + holding[j]->query_short() });
        break;
      case "riposte":
        /* syntax: riposte <person> attack with <weapon>. */
        for (j = 0; j < sizeof(holding) && !check_riposte(holding[j]); j++);
        if (j < sizeof(holding))
          candidates += ({ "riposte " + victim->query_name() +
            " attack with " + holding[j]->query_short() });
        break;
      case "strike":
        /* syntax: strike <person> with <weapon> */
        for (j = 0; j < sizeof(holding) && !check_strike(holding[j]); j++);
        if (j < sizeof(holding))
          candidates += ({ "strike " + victim->query_name() + " with " +
            holding[j]->query_short() });
        break;
      case "disarm":
        /* syntax: disarm <person> */
        if (sizeof(victim->query_weapons()) != 0 && !random(3))
          candidates += ({ "disarm " + victim->query_name()});
        break;
      case "hack":
        /* syntax: hack at <person> with <weapon> */
        for (j = 0; j < sizeof(holding) && !check_hack(holding[j]); j++);
        if (j < sizeof(holding))
          candidates += ({ "hack at " + victim->query_name() + " with " +
            holding[j]->query_short() });
        break;
      case "impale":
        /* syntax: impale <person> with <weapon> */
        for (j = 0; j < sizeof(holding) && !check_impale(holding[j]); j++);
        if (j < sizeof(holding))
          candidates += ({ "impale " + victim->query_name() + " with " +
            holding[j]->query_short() });
        break;
      case "kick":
        /* syntax: kick <person> */
        if(!sizeof(holding - ({ 0 }))) // don't kick if we're holding a weapon.
          candidates += ({ "kick " + victim->query_name() });
        break;
      case "punch":
        /* syntax: punch <person> */
        if (sizeof(this_player()->query_holding() - ({ 0 })) !=
            sizeof(this_player()->query_limbs()))
          candidates += ({ "punch " + victim->query_name() });
        break;
      case "slash":
        /* syntax: slash at <person> with <weapon> */
        for (j = 0; j < sizeof(holding) && !check_slash(holding[j]); j++);
        if (j < sizeof(holding))
          candidates += ({ "slash at " + victim->query_name() + " with " +
            holding[j]->query_short() });
        break;
      default:
        event(environment(victim), "inform", "BUG!  The good fighter shadow "
              "encountered the command " + specials[i] + " in the NPC " +
              file_name(player), "combat");
        log_file(LOGFILE, ctime(time()) + ": BUG.  Don't know how to " +
          "use command " + specials[i] + " in object " + file_name(player) +
          ".\n");
        break;
      }
    }
    if(sizeof(candidates)) {
      cmd = candidates[random(sizeof(candidates))];
#ifdef DEBUG
      event(environment(player), "inform", "Trying to perform: " + cmd,
            "combat");
#endif
      ts->init_command(cmd, 1);
    } else {
#ifdef DEBUG
      event(environment(player), "inform", "No command to perform",
            "combat");
#endif
    }
  } else {
#ifdef DEBUG
    event(environment(player), "inform", "Not doing special this time.",
          "combat");
#endif
  }

  player->fight_in_progress(attacker);
}

/**
 * When a creator uses the 'stat' command on an NPC that is shadowed
 * by this object, this function gets called.  It returns an array
 * containing the normal stats for tho object that this is shadowing,
' * plus it tacks on some information regarding the configuration of
 * this shadow.
 *
 * @return A list of stats related to this shadow, augmented by
 * the stats of the NPC that this shadow is attached to (if any).
 */
mixed *stats()
{
  if (!player || !objectp(player))
    return ({ ({ "good fighter", "unattached" }) });
  return player->stats() + ({
    ({ "good fighter",
      ((bluntorsharp == USE_BLUNT) ? "blunt" :
        ((bluntorsharp == USE_PIERCE) ? "pierce" :
          ((bluntorsharp == USE_SHARP) ? "sharp" : "balanced"))) +
      ((dodgeorparry == DEFEND_DODGE) ? " dodger" :
        ((dodgeorparry == DEFEND_PARRY) ? " parrier" : " fighter")) }),
    ({ "managed commands", implode(specials, ", ") })
  });
}
