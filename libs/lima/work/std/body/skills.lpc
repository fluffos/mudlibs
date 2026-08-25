/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** DESIGN
**
**   Skills are represented as slash-separated names, organized as a tree
**   of skills.  Learning a skill propagates improvement up the chain to
**   the parent skills.  The total, aggregate value of a skill at any point
**   is computed from a skill and all of its parent skills.  This implies
**   that use of one skill can benefit sibling skills; for example, using a
**   sword improves the general combat skill which can help when you are
**   forced to use a polearm (which you are otherwise unskilled at).
**
**   A secondary concept of "training points" exist for each skill.  These
**   represent potential, additional improvement through formal training.
**   Similar to skill values, the training points also propagate upwards.
**   The points can then be applied to the skill and/or back down the tree;
**   for example, using a sword earns training points in combat which can
**   then be applied towards formal training with polearms or archery.
**
** MECHANICS
**
**   Progression within a skill is based on a curve (specifically, a third-
**   order polynomial).  At the low- and top-end of the skill value range,
**   it is hard to advance.  This is to represent the initial difficulty
**   of learning a new skill and the difficulty of perfecting it.  In the
**   middle of the skill value range, growth is much faster (learned points
**   are applied at a near one-to-one ratio).
**
**   At the ends of the range, skills are gained in a proportion based on
**   the LEARNING_FACTOR symbol.
**
**   As learning a skill propogates up the tree of skills, the amount
**   applied decreases exponentially (set by PROPOGATION_FACTOR).
**
**   Training points are added proportionally to the increase in the main
**   skill (set by the TRAINING_FACTOR symbol).
**
**   Learning a skill is based on three symbols: SKILL_ON_FAILURE,
**   SKILL_MIN_ON_WIN, SKILL_MAX_ON_WIN.  When a test_skill() fails, the
**   SKILL_ON_FAILURE amount is learned.  When the test_skill() succeeds,
**   then you learn something in the range of MIN/MAX based on your ratio
**   against the opposing skill (MAX if you're totally outclassed or MIN
**   if you stomp all over your opponent).
**
**   All these parameters are set in the config/skills.h file.
**
** Note: policy decision says that we aren't protecting skills from
**       "unauthorized" tampering.  This is consistent with much of
**       lib -- wizards can help players in any numbers of ways and
**       we won't try to guard against all of them.
*/

#include <classes.h>
#include <config/skills.h>
#include <hooks.h>

inherit CLASS_SKILL;

private
mapping skills = ([]);
private
nosave mapping skill_ranks = ([]);
private
nosave mixed ranks = SKILL_D->ranks();
private
nosave mapping skill_bonus = ([]);

int base_test_skill(string skill, int opposing_skill);

//: FUNCTION initiate_ranks
// int initiate_ranks();
// Function to build our cache of current skill ranks.
//
// This allows us to track whenever we move up a rank without
// recalculating them all the time. This is called on first call to
// query_skill_ranks().
int initiate_ranks()
{
   if (sizeof(keys(skill_ranks)) == 0)
   {
      foreach (string skill_name in keys(skills))
      {
         skill_ranks[skill_name] = SKILL_D->rank_name_from_pts(skills[skill_name].skill_points);
      }
      return 1;
   }
   return -1;
}

int cached_skill_rank(string s)
{
   if (!sizeof(keys(skill_ranks)))
      initiate_ranks();
   return skill_ranks[s];
}

//: FUNCTION banner_rankup
// void banner_rankup(string skill, int rank);
// Tell this_object() that we just ranked up in a nice and colourful way.
void banner_rankup(string skill, int rank)
{
   tell(this_object(),
        "\n>>>>> %^B_YELLOW%^RANK UP!%^RESET%^ You're now rank " + rank + " in " + capitalize(skill) + " <<<<<\n");
}

//: FUNCTION check_rank
// int check_rank(string skill_name,int sp);
// The actual check for whether or not we ranked up happens here.
// If we did rank up banner_rankup() is called and rank cache is updated.
int check_rank(string skill_name, int sp)
{
   int rank = 0;
   int rank_up = 0;

   while (rank < (sizeof(ranks) - 1) && sp > ranks[rank])
   {
      rank++;
   }
   // TBUG(this_object()+"Name: "+skill_name+" Cached rank: "+skill_ranks[skill_name]+" calc rank: "+rank+" Skillpoints:
   // "+sp);

   rank_up = rank > skill_ranks[skill_name] ? 1 : 0;
   if (rank_up)
   {
      banner_rankup(skill_name, rank);
      skill_ranks[skill_name] = rank;
   }

   return rank_up;
}

//: FUNCTION query_skill_ranks
// mapping query_skill_ranks() ;
// Returns the skill_ranks mapping.
mapping query_skill_ranks()
{
   initiate_ranks();
   return skill_ranks;
}

//: FUNCTION set_skill
// class skill set_skill(string skill, int skill_points, int training_points);
// Function for creating class skill and settings them directly into the player.
// Mostly called internally in BODY, but can be used for testing by wizards.
//
// i.e. give me 100 skill_points and 20 training_points in combat/sword:
// @.me->set_skill("combat/melee/blade",100,20)
class skill set_skill(string skill, int skill_points, int training_points)
{
   class skill cs = skills[skill];

   if (member_array(skill, SKILL_D->query_skills()) == -1)
      error("illegal skill '" + skill + "'; cannot set new skill values.\n");

   if (!cs)
   {
      cs = skills[skill] = new (class skill, skill_points : skill_points, training_points : training_points);
   }
   else
   {
      cs.skill_points = skill_points;
      cs.training_points = training_points;
   }

   return cs;
}

//: FUNCTION clear_training_points
// class skill clear_training_points(string skill);
// Sets a skill to 0 training points. Typically used by
// M_TRAINER. Checks if the skill exists for the player.
// Returns the class skill after the modification.
class skill clear_training_points(string skill)
{
   class skill cs = skills[skill];
   if (!cs)
      error("Cannot clear training points in non-existing skill " + skill + ".\n");

   cs.training_points = 0;

   return cs;
}

//: FUNCTION query_skills
// mapping query_skills();
// Returns the underlying skills mapping with skill classes from the player.
mapping query_skills()
{
   return skills;
}

//: FUNCTION zero_skills
// void zero_skills();
// Delete all skills for a body.
void zero_skills()
{
   skills = ([]);
}

//: FUNCTION clean_skills
// void clean_skills();
// Removes skills from the player that doesn't exist anymore.
void clean_skills()
{
   foreach (string skill in keys(skills))
   {
      if (member_array(skill, SKILL_D->query_skills()) == -1)
         map_delete(skills, skill);
   }
}

//: FUNCTION query_skill
// class skill query_skill(string skill);
// Returns a single class skill by name.
class skill query_skill(string s)
{
   class skill skill;
   if (!skills[s])
      return 0;
   skill = copy(skills[s]);
   skill.skill_points = CLAMP(skill.skill_points+skill_bonus[s],0,MAX_SKILL_VALUE);
   return skill;
}

//: FUNCTION query_skill_pts
// int query_skill_pts(string skill);
// Returns the current skill points for a skill.
// This is not the aggregated points, but the real number
// of points at this spot of the skill tree.
// Returns -1 if the skill doesn't exist for the player.
int query_skill_pts(string skill)
{
   if (skills[skill])
      return skills[skill].skill_points;
   return -1;
}

void add_skill_bonus(string s, int v)
{
   class skill skill, new_skill;
   if (!skills[s])
      skills[s] = new (class skill);
   if (!skill_bonus[s])
      skill_bonus[s] = 0;
   skill_bonus[s] += v;
}

void remove_skill_bonus(string s, int v)
{
   add_skill_bonus(s, (-1 * v));
}

//: FUNCTION query_skill_bonus
// int query_skill_bonus(string skill);
// Returns the current skill bonus for a skill.
// Returns -1 if the skill doesn't exist for the player.
int query_skill_bonus(string skill)
{
   if (skills[skill])
      return skill_bonus[skill];
   return -1;
}

//: FUNCTION query_training_pts
// int query_training_pts(string skill);
// Returns the current training points for a skill.
// Returns -1 if the skill doesn't exist for the player.
int query_training_pts(string skill)
{
   if (skills[skill])
      return skills[skill].training_points;
   return -1;
}

//: FUNCTION aggregate_skill
// Returns the aggregated skill value for the specified skill.  This value
// incorporates the value of the skill itself plus all values of the parent
// skills.
int aggregate_skill(string skill)
{
   int total_skill = 0;
   int coef = 1;

   // total_skill += this_object()->call_hooks("modify_skill", HOOK_SUM, 0, skill);
   while (1)
   {
      class skill my_skill;
      int i;

      my_skill = skills[skill];
      if (my_skill)
      {
         total_skill += fuzzy_divide(my_skill.skill_points, coef);
      }

      coef = coef * AGGREGATION_FACTOR;

      i = strsrch(skill, '/', -1);
      if (i == -1)
         break;
      skill = skill[0..i - 1];
   }

   return total_skill;
}

//: FUNCTION learn_skill
// Add some number of skill points to the given skill, propogating skill
// values up through the parent skills.  Training points are also assigned
// as appropriate.
void learn_skill(string skill, int value)
{
   initiate_ranks();
   while (1)
   {
      class skill my_skill;
      int divisor;
      int i;
      int s;

      my_skill = skills[skill];
      if (!my_skill)
      {
         /* use set_skill() for verification of the skill */
         my_skill = set_skill(skill, 0, 0);
      }

      /* centered within skill range */
      s = my_skill->skill_points - (MAX_SKILL_VALUE / 2);

      /* as a person's skill increases, the amount they learn decreases */
      divisor = ((LEARNING_FACTOR - 1) * s * s) / (MAX_SKILL_VALUE * MAX_SKILL_VALUE / 4) + 1;
      my_skill.skill_points += fuzzy_divide(value, divisor);
      check_rank(skill, my_skill.skill_points);
      // TBUG("Skill: "+skill+" s: "+s+" Divisor: "+divisor+" Value: "+value+" Points gained: "+fuzzy_divide(value,
      // divisor)+" Prop: "+fuzzy_divide(value, PROPAGATION_FACTOR));

      if (my_skill.skill_points > MAX_SKILL_VALUE)
         my_skill.skill_points = MAX_SKILL_VALUE;

      /* accum training points */
      my_skill.training_points += fuzzy_divide(value, divisor * TRAINING_FACTOR);

      /* as skill moves up (<-) the tree, it decreases */
      value = fuzzy_divide(value, PROPAGATION_FACTOR);
      if (!value)
         break;

      i = strsrch(skill, '/', -1);
      if (i == -1)
         break;
      skill = skill[0..i - 1];
   }
}

//: FUNCTION test_skill
// This replaces the basic adversary test_skill function,
// adding an attempt to improve the skill
varargs int test_skill(string skill, int opposing_skill, int no_learn)
{
   int total_skill;
   int amount;
   int combined_total;
   int res;

   total_skill = aggregate_skill(skill);
   combined_total = total_skill + opposing_skill;
   res = base_test_skill(skill, opposing_skill);
   if (combined_total < 0)
      combined_total = 0;

   // If we cannot learn here, don't learn
   if (!no_learn)
   {
      /*
      ** Successful skill attempts win a number of skill points based on
      ** the ratio between the total_skill and opposing_skill.
      **
      ** The range is MIN to MAX, centered between the two for evenly matched
      ** skills.  As the opposing skill increases, so does the amount learned.
      */
      if (res)
      {
         amount = (((SKILL_MAX_ON_WIN - SKILL_MIN_ON_WIN) * opposing_skill + (combined_total / 2)) /
                   (combined_total + SKILL_MIN_ON_WIN));
         learn_skill(skill, amount);
      }
      else
         learn_skill(skill, SKILL_ON_FAILURE);
   }
   return res;
}

//: FUNCTION query_evaluation
// Returns the player's overall evaluation (0 to 100 percent) of their skill
// level.  This evaluation corresponds to how they are doing with respect
// to the maximum possible skill level.
int query_evaluation()
{
   return implode(values(skills), ( : $1 + ((class skill)$2)->skill_points:), 0) * 100 / EVALUATION_SKILL_LEVEL;
}
