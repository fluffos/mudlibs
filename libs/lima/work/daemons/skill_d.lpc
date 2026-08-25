/* Do not remove the headers from this file! see /USAGE for more info. */

#include <classes.h>
#include <config/skills.h>
#include <security.h>

inherit M_DAEMON_DATA;
inherit CLASS_SKILL;

/*
** Keep the list of the available skills.
**
** NOTE: The values in this mapping are unused (set to 1)
*/
private
mapping skills = ([]);
private
nosave mixed skill_ranks = ({100,  250,  500,  750,  1000, 1250, 1500, 2000, 2500, 3000,
                             3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 8000, 10000});
#ifdef USE_ROMAN_NUMERALS
private
nosave mixed skill_titles = ({"",   "I",   "II",   "III", "IV", "V",   "VI",   "VII",   "VIII", "IX", "X",
                              "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX",  "XX"});
int roman_numerals()
{
   return 1;
}

#else
private
nosave mixed skill_titles = ({"",   "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9", "10",
                              "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"});
#endif

#define PRIV_REQUIRED "Mudlib:daemons"

string *register_skill(string skill)
{
   string *parts;
   string *result;

   if (!check_privilege(PRIV_REQUIRED))
      error("security: illegal attempt to add a skill\n");

   if (skills[skill])
      return 0;

   /* create the skill and all parent skills */
   parts = explode(skill, "/");
   result = allocate(sizeof(parts));
   for (int i = sizeof(parts); i--;)
   {
      string name = implode(parts[0..i], "/");

      if (!skills[name])
      {
         result[i] = name;
         skills[result[i]] = 1;
      }
   }

   save_me();

   return filter(result, ( : $1:));
}

string *remove_skill(string skill)
{
   string *result = ({skill});

   if (!check_privilege(PRIV_REQUIRED))
      error("security: illegal attempt to remove a skill\n");

   if (!skills[skill])
      return 0;

   /* delete the skill */
   map_delete(skills, skill);

   /* delete all subskills: skills that start with <skill> + "/" */
   skill = skill + "/";
   foreach (string name in keys(skills))
      if (strsrch(name, skill) == 0)
      {
         map_delete(skills, name);
         result += ({name});
      }

   save_me();

   return result;
}

string *query_skills()
{
   return sort_array(keys(skills), 1);
}

int valid_skill(string s)
{
   return member_array(s, query_skills()) != -1;
}

int pts_for_rank(int rank)
{
   rank--;
   if (rank < 0)
      return 0;
   return skill_ranks[rank];
}

int skill_title_from_pts(int skill_pts)
{
   int rank = 0;

   while (skill_pts > skill_ranks[rank])
   {
      rank++;
   }
   return skill_titles[rank];
}

int rank_name_from_pts(int skill_pts)
{
   int rank = 0;

   while (skill_pts > skill_ranks[rank])
   {
      rank++;
   }
   return rank;
}

int skill_rank(object player, string skill_name)
{
   class skill skill;
   int rank = 0;

   skill = player->query_skill(skill_name);
   if (!skill)
      return 0;
   while (skill.skill_points > skill_ranks[rank])
   {
      rank++;
   }
   return rank;
}

int monster_skill_rank(object player, string skill_name)
{
   int skill_pts;
   int rank = 0;

   skill_pts = player->query_skill(skill_name);
   if (!skill_pts)
      return 0;
   while (skill_pts > skill_ranks[rank])
   {
      rank++;
   }
   return rank;
}

mixed titles()
{
   return skill_titles;
}

mixed ranks()
{
   return skill_ranks;
}

string skill_req_pretty(string skill_name, int rank)
{
   string name = explode(skill_name, "/")[ < 1];
   return capitalize(name) + (rank > 0 ? " [" + skill_titles[rank] + "]" : "");
}

string skill_rank_pretty(object player, string skill_name)
{
   int level = sizeof(explode(skill_name, "/"));
   string name = explode(skill_name, "/")[ < 1];
   int rank = skill_rank(player, skill_name);
   return capitalize(name) + (rank > 0 ? " [" + skill_titles[rank] + "]" : "");
}

string monster_skill_rank_pretty(object mob, string skill_name)
{
   int level = sizeof(explode(skill_name, "/"));
   string name = explode(skill_name, "/")[ < 1];
   int rank = monster_skill_rank(mob, skill_name);
   return capitalize(name) + (rank > 0 ? " [" + skill_titles[rank] + "]" : "");
}

string skill_rank_simple(object player, string skill_name)
{
   int rank = skill_rank(player, skill_name);
   string name = strsrch(skill_name, "/") != -1 ? implode(explode(skill_name, "/")[1..], "/") + " rank " + rank
                                                : upper_case(skill_name);
   return name;
}

int percent_for_next_rank(object player, string skill_name)
{
   class skill skill;
   int rank = skill_rank(player, skill_name);
   int next_rank = skill_ranks[rank] - (rank == 0 ? 0 : skill_ranks[rank - 1]);
   skill = player->query_skill(skill_name);
   if (!skill)
      return 0;

   return (skill->skill_points - (rank == 0 ? 0 : skill_ranks[rank - 1])) * 100 / next_rank;
}

int monster_percent_for_next_rank(object mob, string skill_name)
{
   int skill_pts;
   int rank = monster_skill_rank(mob, skill_name);
   int next_rank = skill_ranks[rank] - (rank == 0 ? 0 : skill_ranks[rank - 1]);
   if (!next_rank)
      next_rank = 1;
   skill_pts = mob->query_skill(skill_name);
   if (!skill_pts)
      return 0;

   return (skill_pts - (rank == 0 ? 0 : skill_ranks[rank - 1])) * 100 / next_rank;
}

void create()
{
   ::create(); //Restore values from .o file
   if (MAX_SKILL_VALUE != 10000)
   {
      float factor = (MAX_SKILL_VALUE * 1.0) / 10000;
      skill_ranks = map_array(skill_ranks, ( : to_int($1 * $(factor)) :));
   }
}