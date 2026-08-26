// Last edited by deforce on 03-12-2010
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
string skill_name;
int skill_penalty;

void create(string skill, int penalty, int duration)
{
   buff::create();

   skill_name = skill;
   skill_penalty = penalty;

   if (skill_penalty > 0)
   {
      skill_penalty *= -1;
   }

   set_buff_duration(duration);
}

int query_skill_penalty()
{
   return skill_penalty;
}

void apply_buff(object target)
{
   my_hook = (: query_skill_penalty :);
   target->add_hook(skill_name + "_skill_bonus", my_hook);

   target->other_action("$N seems to forget some of what $n has learned.\n", target);
   tell(target, "%^BOLD%^%^RED%^You forget some of what you've learned about " + lower_case(SKILL_D->query_skill(skill_name)[0]) + ".%^RESET%^\n");
}

void remove_buff(object target)
{
   target->remove_hook(skill_name + "_skill_bonus", my_hook);

   target->other_action("$N seems to recover $p memory.\n");
   tell(target, "%^BOLD%^You remember what you've learned about " + lower_case(SKILL_D->query_skill(skill_name)[0]) + ".%^RESET%^\n");
}