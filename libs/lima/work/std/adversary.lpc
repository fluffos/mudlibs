/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * ADVERSARY: Beek, April 7, 1997.  Loosely based on the old monster.c
 *   Lots of work done by Iizuka to get this working.
 */


inherit LIVING;
inherit M_DAMAGE_SOURCE;
inherit M_BODY_STATS;

#define SUBDIR __DIR__ "adversary/"

inherit SUBDIR "main";
inherit SUBDIR "behaviors";
inherit SUBDIR "condition";
inherit SUBDIR "target";
inherit SUBDIR "messages";
inherit SUBDIR "mod_config";
inherit SUBDIR "armour/armour_base";
inherit SUBDIR "wield/wield_base";
#ifdef USE_SKILLS
inherit SUBDIR "skills";
#endif
inherit SUBDIR "monster";

inherit MODULE("death", DEATH_MODULE);
inherit MODULE("health", HEALTH_MODULE);
inherit MODULE("wield", WIELD_MODULE);
inherit MODULE("armour", ARMOUR_MODULE);
inherit MODULE("pulse", PULSE_MODULE);
inherit MODULE("blows", BLOW_MODULE);
inherit MODULE("formula", FORMULA_MODULE);
inherit MODULE("advancement", ADVANCEMENT_MODULE);

#include <stats.h>

void mudlib_setup(mixed *args...)
{
   living::mudlib_setup(args...);
   // Please read the headers in /std/adversary/mod_config.c before
   // removing this line.
   check_combat_config();
   set_to_hit_bonus(-25); // -25% to hit bare hand.
   set_weapon_class(3);   // and low WC
   set_combat_messages("combat-unarmed");
   set_death_message(query_default_death_message());

   /* by pinging query_weapon(), we will default to self as a weapon */
   query_weapon();
   call_out("setup_monster", 0);
}

//: FUNCTION start_fight
// Add someone to the list of people we are attacking.  If we were already
// attacking them, make them the primary person we are attacking.  Then
// take a swing at them.
int start_fight(object who)
{
   if (!(who->attackable()))
      return 0;
   attacked_by(who, 1);
   return 1;
}

void setup_monster()
{
   if (!this_object()->is_body())
      setup_monster_defaults();
}

//: FUNCTION attackable
// return 1 if we can be attacked.
int attackable()
{
   return environment() && !environment()->query_combat_forbidden();
}

mixed direct_diagnose_liv(object ob)
{
   return 1;
}

mixed direct_kill_liv(object ob)
{
   if (query_ghost())
      return "Someone beat you to it; " + the_short() + " is already dead.\n";
   return 1;
}

//: FUNCTION query_ghost
// Returns 1 if the adversary is dead.
int query_ghost()
{
   return HEALTH_MODULE::query_ghost();
}

#ifdef USE_KARMA
//: FUNCTION karma_impact
// int karma_impact();
// Override and return a number between -5 and 5 to impact karma
// when killed by someone
int karma_impact()
{
   return 0;
}
#endif

int event_damage(class event_info evt)
{
   return BLOW_MODULE::event_damage(evt);
}

//: FUNCTION diagnose
// Returns a string describing the current state of the adversary.
string diagnose()
{
   return HEALTH_MODULE::diagnose();
}

/*
 * Ok, quick explanation:
 *
 * FOO_BAR_FACTOR gives the percentage of FOO that is based on BAR.
 *
 * derived stats are based on the main stats, plus a portion which
 * depends on race, which is scaled by an amount which is the racial
 * bonus.
 *
 * Derive the coefficients of the transformation, to make things easier
 * later.
 */
/*
** Effects of the base stats on the derived stats
*/
int racial_con_bonus()
{
}

int racial_wis_bonus()
{
}

int racial_cha_bonus()
{
}

int racial_man_bonus()
{
}

nomask int *query_transformation_matrix()
{
   if (clonep())
      return base_name()->query_transformation_matrix();

   return ({
       map(({CON_STR_FACTOR, CON_AGI_FACTOR, 0, CON_WIL_FACTOR}), (
                                                                      : $1 * $(100 - racial_con_bonus())
                                                                      :)),
       map(({WIS_STR_FACTOR, WIS_AGI_FACTOR, WIS_INT_FACTOR, WIS_WIL_FACTOR}),
           (
               : $1 * $(100 - racial_wis_bonus() - WIS_SKILL_FACTOR)
               :)),
       map(({CHA_STR_FACTOR, CHA_AGI_FACTOR, CHA_INT_FACTOR, CHA_WIL_FACTOR}),
           (
               : $1 * $(100 - racial_cha_bonus() - CHA_SKILL_FACTOR)
               :)),
       map(({CHA_STR_FACTOR, 0, CHA_INT_FACTOR, CHA_WIL_FACTOR}),
           (
               : $1 * $(100 - racial_man_bonus() - MAN_SKILL_FACTOR)
               :)),
   });
}

nomask int *query_constant_vector()
{
   if (clonep())
      return base_name()->query_constant_vector();

   return ({racial_con_bonus(), racial_wis_bonus(), racial_cha_bonus(), racial_man_bonus()});
}

#ifdef USE_SKILLS
private
string defend_skill_used = "combat/defense/dodge";

string query_defend_skill_used()
{
   // Can be removed once gone from all .o files
   if (defend_skill_used == "combat/dodge")
      defend_skill_used = "combat/defense/dodge";
   return defend_skill_used;
}

void set_defend_skill_used(string skill)
{
   defend_skill_used = skill;
}
#endif
