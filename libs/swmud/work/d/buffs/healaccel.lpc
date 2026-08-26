// Last edited by deforce on 07-12-2008
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
int heal_bonus;

void create(int bonus, int duration)
{
   buff::create();

   heal_bonus = bonus;

   set_buff_duration(duration);
}

int query_heal_bonus()
{
   return heal_bonus;
}

void apply_buff(object target)
{
   my_hook = (: query_heal_bonus :);
   target->add_hook("heal_rate_bonus", my_hook);
   target->refresh_stats();

   target->other_action("$N $vare surrounded by a steady, faint blue glow.\n");
}

void remove_buff(object target)
{
   target->update_health();
   target->remove_hook("heal_rate_bonus", my_hook);
   target->refresh_stats();

   target->other_action("The blue glow around $N fades away.\n");
   tell(target, "%^BOLD%^Your healing is no longer accelerated.%^RESET%^\n");
}