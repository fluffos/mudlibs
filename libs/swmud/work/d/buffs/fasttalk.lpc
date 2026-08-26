// Last edited by deforce on 10-07-2009
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
int hit_penalty;

void create(int penalty, int duration)
{
   buff::create();

   hit_penalty = penalty;

   set_buff_duration(duration);
}

int query_hit_penalty()
{
   return hit_penalty;
}

void apply_buff(object target)
{
   my_hook = (: query_hit_penalty :);
   target->add_hook("to_hit_bonus", my_hook);
}

void remove_buff(object target)
{
   tell(target, "%^BOLD%^You are now able to focus on combat.%^RESET%^\n");
   target->other_action("$N is able to focus on combat again.");
   target->remove_hook("to_hit_bonus", my_hook);
}