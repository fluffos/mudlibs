/* Do not remove the headers from this file! see /USAGE for more info. */

#include <classes.h>
#include <config/skills.h>
#include <security.h>

//: MODULE
// This daemon keeps track of valid skills, registers new skills, and removes unwanted
// skills. It also creates percentages for skills, calculates skill ranks for players
// and monsters (Wait, skill ranks for monsters? Yes, you can use the ``skills`` command
// to see which skills your monsters have.)
//
// A couple of useful commands:
//
//    - Dump current skills to config file: ``@SKILL_D->dump_skills_to_file()``
//    - Load skills from config file: ``@SKILL_D->init_skills()``
//
// This might eventually get an admtool interface.
//
// .. TAGS: RST

inherit M_DAEMON_DATA;
inherit CLASS_SKILL;

#define SKILL_FLAT_FILE "/data/config/skill-tree"

/*
** Keep the list of the available skills.
**
** NOTE: The values in this mapping are unused (set to 1)
*/
private
mapping skills = ([]);
private
nosave mixed skill_ranks = ({100,  250,  500,  750,  1000, 1250, 1500, 1750, 2000, 2500, 3000,
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

//: FUNCTION register_skill
// Register a new skill with the daemon. This function needs
// the Mudlib:daemons privilege.
// Example:
//
//     register_skill("combat/melee/grenade");
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

//: FUNCTION remove_skill
// Removes a skill from the daemon. This function needs
// the Mudlib:daemons privilege.
// Example:
//
//     remove_skill("combat/melee/grenade");
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

//: FUNCTION query_skills
// Returns a string array of all the skills in the daemon.
string *query_skills()
{
   return sort_array(keys(skills), 1);
}

//: FUNCTION valid_skill
// Check if argument is a valid skill or not.
int valid_skill(string s)
{
   return member_array(s, query_skills()) != -1;
}

//: FUNCTION pts_for_rank
// Returns the skill points needed to achieve a specific rank. This is the reverse of the
// ``skill_title_from_pts(int skill_pts)`` method.
int pts_for_rank(int rank)
{
   rank--;
   if (rank < 0)
      return 0;
   return skill_ranks[rank];
}

//: FUNCTION skill_title_from_pts
// Returns which skill rank you should have if you have ``skill_pts``
// number of points in your skill. This is the reverse of the
// ``pts_for_rank(int rank)`` method.
int skill_title_from_pts(int skill_pts)
{
   int rank = 0;

   while (skill_pts > skill_ranks[rank])
   {
      rank++;
   }
   return skill_titles[rank];
}

//: FUNCTION rank_name_from_pts
// Returns the rank from a given set of ``skill_pts``.
// This function is similar to the ``skill_title_from_pts`` method.
int rank_name_from_pts(int skill_pts)
{
   int rank = 0;

   while (skill_pts > skill_ranks[rank])
   {
      rank++;
   }
   return rank;
}

//: FUNCTION skill_rank
// Returns the skill rank for a player of a specific
// skill.
int skill_rank(object player, string skill_name)
{
   class skill skill;
   int rank = 0;

   if (!player)
      return 0;

   skill = player->query_skill(skill_name);
   if (!skill)
      return 0;
   if (classp(skill))
      while (skill.skill_points > skill_ranks[rank])
      {
         rank++;
      }
   else if (intp(skill))
      rank = rank_name_from_pts((int)skill);
   return rank;
}

//: FUNCTION skill_rank
// Returns the skill rank for a monster of a specific
// skill. Monsters have a simpler skill structure, so
// they are handled separately.
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

//: FUNCTION titles
// Returns the titles of all the ranks.
mixed titles()
{
   return skill_titles;
}

//: FUNCTION ranks
// Returns the ranks (thresholds) of skill points you have
// to hit to gain a new skill rank.
mixed ranks()
{
   return skill_ranks;
}

//: FUNCTION skill_req_pretty
// Returns a string that clearly communicates a skill name
// and a rank in the current rank scheme defined in ``<config/skills.h>``.
//
//     @SKILL_D->skill_req_pretty("/combat/sword",12) --> "Sword [XII]"
//
// This is used in M_DAMAGE_SOURCE to tell players about skill restrictions
// to weapons.
string skill_req_pretty(string skill_name, int rank)
{
   string name = explode(skill_name, "/")[ < 1];
   return capitalize(name) + (rank > 0 ? " [" + skill_titles[rank] + "]" : "");
}

//: FUNCTION skill_rank_pretty
// Returns a string that clearly communicates a skill name
// and a rank in the current rank scheme defined in <config/skills.h>.
//
//     @SKILL_D->skill_rank_pretty(.me,"combat/melee/blade")--> "Blade [2]"
//
string skill_rank_pretty(object player, string skill_name)
{
   int level = sizeof(explode(skill_name, "/"));
   string name = explode(skill_name, "/")[ < 1];
   int rank = skill_rank(player, skill_name);
   return capitalize(name) + (rank > 0 ? " [" + skill_titles[rank] + "]" : "");
}

//: FUNCTION monster_skill_rank_pretty
// Same as ``skill_rank_pretty()`` but for monsters.
string monster_skill_rank_pretty(object mob, string skill_name)
{
   int level = sizeof(explode(skill_name, "/"));
   string name = explode(skill_name, "/")[ < 1];
   int rank = monster_skill_rank(mob, skill_name);
   return capitalize(name) + (rank > 0 ? " [" + skill_titles[rank] + "]" : "");
}

//: FUNCTION skill_rank_simple
// Returns a simplestring that clearly communicates a skill name
// and a rank. This is default output for screen readers.
string skill_rank_simple(object player, string skill_name)
{
   int rank = skill_rank(player, skill_name);
   string name = strsrch(skill_name, "/") != -1 ? implode(explode(skill_name, "/")[1..], "/") + " rank " + rank
                                                : upper_case(skill_name);
   return name;
}

//: FUNCTION init_skills
// Load /data/config/skill-tree as new skill configuration.
void init_skills()
{
   string *config = explode(read_file(SKILL_FLAT_FILE), "\n");
   skills = ([]);

   foreach (string line in config)
   {
      if (line[0] == '#')
         continue;
      sscanf(line, "%s:%*d", line);
      register_skill(line);
   }
   write(SKILL_FLAT_FILE + " loaded.");
}

//: FUNCTION dump_skills_to_file
// Dump all skills to /data/config/skill-tree.
void dump_skills_to_file()
{
   string section;
   string out =
       "# Skill tree for the SKILL_D\n"
       "# Use @SKILL_D->dump_skills_to_file() to write skills to this file\n"
       "# Use @SKILL_D->init_skills() to read skills from this file - this will remove all old skills.\n"
       "# The values after the skill names are currently unused, but may be used later. Keep them at 1 for now.\n";
   foreach (string skill in sort_array(keys(skills), 1))
   {
      string root = explode(skill, "/")[0];
      if (root != section)
      {
         section = root;
         out += "\n# " + capitalize(root) + " section\n";
      }
      out += skill + ":" + (skills[skill] ? "1 " : "0") + "\n";
   }

   unguarded(1, ( : write_file, SKILL_FLAT_FILE, out, 1 :));
   write("Skills dumped to " + SKILL_FLAT_FILE + ".");
}

//: FUNCTION percent_for_next_rank
// Returns the percent until the player hits the next skill rank.
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

//: FUNCTION monster_percent_for_next_rank
// Returns the percent until the monster hits the next skill rank.
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
   ::create(); // Restore values from .o file
   set_privilege(PRIV_REQUIRED);
   if (MAX_SKILL_VALUE != 10000)
   {
      float factor = (MAX_SKILL_VALUE * 1.0) / 10000;
      skill_ranks = map_array(skill_ranks, ( : to_int($1 * $(factor)) :));
   }
}