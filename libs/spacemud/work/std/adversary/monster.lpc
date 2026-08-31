/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** Monster setup functions. Must be as small as possible
** since players carry this code as well.
*/

#include <config/skills.h>

#define MAX_MONSTER_LEVEL 100

int query_level();
void set_skill(string name, int sp);
void set_str(int);
void set_agi(int);
void set_int(int);
void set_wil(int);
void update_max_health();
void heal_all();
void set_natural_armour(int na);
void set_damage_bonus(int x);
void add_id(string *id...);
void init_stats();
varargs int query_max_capacity(string relation);

private
nosave int max_skill;
private
nosave string monster_race;

int stats_for_Level()
{
   return 4 + (query_level() * 4);
}

void set_race(string r)
{
   add_id(r);
   monster_race = r;
}

string query_race()
{
   return monster_race;
}

// Tricky function! Basically, this scales the monsters
// skills like the player skills. They do not reach the next rank
// right before they can.
private
int skill_for_level()
{
   int below, current;
   if (max_skill)
      return max_skill;
   current = SKILL_D->pts_for_rank(query_level() / 5);
   below = SKILL_D->pts_for_rank((query_level() / 5) - 1);
   max_skill = (((0.0 + query_level()) / 5 - floor(query_level() / 5)) * (current - below)) + below;

   return max_skill || (query_level() * 10);
}

// Overwritten by BODY if a player.
varargs int query_no_move_capacity(string relation)
{
   return to_int(query_max_capacity() * 0.9);
}

void setup_monster_defaults()
{
   string *skills = SKILL_D->query_skills();
   int sp = skill_for_level();
   if (this_object()->is_body())
      return;

   init_stats();
   set_natural_armour(query_level() / 2);
   set_damage_bonus(query_level() / 2);

   foreach (string skill in skills)
   {
      set_skill(skill, sp);
   }
   /*
   set_str(query_level());
   set_agi(query_level());
   set_int(query_level());
   set_wil(query_level());
   */
   update_max_health();
   heal_all();
}
