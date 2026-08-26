// Last edited by deforce on 10-21-2009
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
string skill_name;
int skill_bonus;

void create(string skill, int bonus, int duration)
{
   buff::create();

   skill_name = skill;
   skill_bonus = bonus;

   set_buff_duration(duration);
}

int query_skill_bonus()
{
   return skill_bonus;
}

void apply_buff(object target)
{
   my_hook = (: query_skill_bonus :);
   target->add_hook(skill_name + "_skill_bonus", my_hook);
   target->refresh_stats();
}

void remove_buff(object target)
{
   target->remove_hook(skill_name + "_skill_bonus", my_hook);
   target->refresh_stats();
}