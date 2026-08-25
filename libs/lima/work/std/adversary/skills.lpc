/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Extended to more than simple support for skills by Tsath.
** You can now add skills to monsters and use them in much the same way
** players do. They do NOT, however, learn or gain skillpoints.
** More extensive skill support for players is found in /std/body/skills.c
*/

#include <config/skills.h>

int query_level();

private
nosave mapping adversary_skills = ([]);

//: FUNCTION aggregate_skill
// This value is a simple sum of the set skill value for the mob if any
// + the query_level() of the monster.
int aggregate_skill(string skill)
{
   int pts = 0;
   int coef = 1;
   for (int i = 0; i < sizeof(explode(skill, "/")); i++)
   {
      pts += adversary_skills[skill] / coef;
      coef = coef * AGGREGATION_FACTOR;
   }
   return pts;
}

//: FUNCTION set_skill
// This provides a simple way to set skills for adversaries.
// Example @.here:guard->set_skill("combat/melee/club",1000);
//
// No need to set "combat" as well for adversaries since the skills do
// not aggregate like for players with bodies. Once set, a skill cannot be changed.
// Use force_skill() to override this restriction.
void set_skill(string name, int sp)
{
   if (!adversary_skills[name])
      adversary_skills[name] = sp;
}

//: FUNCTION force_skill
// This provides a simple way to set skills for adversaries.
// Example @.here:guard->force_skill("combat/melee/club",1000);
//
// Unlike set_skill(), force_skill() in adversary can set a skill even if set previously.
void force_skill(string name, int sp)
{
   adversary_skills[name] = sp;
}

int cached_skill_rank(string s)
{
   return query_level();
}

int query_skill_pts(string skill)
{
   if (adversary_skills[skill])
      return adversary_skills[skill];
   return 0;
}

mapping query_skills()
{
   return adversary_skills;
}

int query_skill(string skill)
{
   return query_skill_pts(skill);
}

//: FUNCTION base_test_skill
// Test whether this adversary' skill succeeds against a given opposing skill
// level.  Returns 1 for success of this user.
int base_test_skill(string skill, int opposing_skill)
{
   int total_skill;
   int combined_total;

   total_skill = aggregate_skill(skill);
   combined_total = total_skill + opposing_skill;

   /*
    ** If both participants are unskilled, then make them evenly matched.
    ** (and avoid divide by zero errors :-)
    */
   if (!combined_total)
   {
      total_skill = opposing_skill = 1;
      combined_total = 2;
   }

   /*
    ** total_skill should be total_skill/opposing_skill more likely to win
    ** than opposing_skill.  The formula below works this way.  For example,
    ** total_skill == 100, opposing_skill == 50.  This user has a 2/3 chance
    ** of winning.
    */
   if (random(combined_total) < opposing_skill) // FAILED
      return 0;

   return 1;
}

//: FUNCTION test_skill
// This is the basic skill test for adversaries.
// For players it is replaced by an extended version, supporting the
// improvement of skills through use.
varargs int test_skill(string skill, int opposing_skill, int no_learn)
{
   return base_test_skill(skill, opposing_skill);
}
