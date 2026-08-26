// Last edited by deforce on 10-10-2009
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
int stat_bonus;

void create(int bonus, int duration)
{
   buff::create();

   stat_bonus = bonus;

   set_buff_duration(duration);
}

int query_stat_bonus()
{
   return stat_bonus;
}

void apply_buff(object target)
{
   my_hook = (: query_stat_bonus :);
   target->add_hook("str_bonus", my_hook);
   target->add_hook("con_bonus", my_hook);
   target->add_hook("agi_bonus", my_hook);
   target->add_hook("dex_bonus", my_hook);
   target->add_hook("per_bonus", my_hook);
   target->add_hook("int_bonus", my_hook);
   target->add_hook("cha_bonus", my_hook);
   target->add_hook("luc_bonus", my_hook);
   target->add_hook("for_bonus", my_hook);
   target->refresh_stats();

   target->other_action("$N $vare surrounded by a steady, yellow glow.\n");
   tell(target, "You feel the Force flow through you, strengthening your body.\n");
}

void remove_buff(object target)
{
   target->remove_hook("str_bonus", my_hook);
   target->remove_hook("con_bonus", my_hook);
   target->remove_hook("agi_bonus", my_hook);
   target->remove_hook("dex_bonus", my_hook);
   target->remove_hook("per_bonus", my_hook);
   target->remove_hook("int_bonus", my_hook);
   target->remove_hook("cha_bonus", my_hook);
   target->remove_hook("luc_bonus", my_hook);
   target->remove_hook("for_bonus", my_hook);
   target->refresh_stats();

   target->other_action("The yellow glow around $N fades away.\n");
   tell(target, "%^BOLD%^Your body is no longer strengthened by the Force.%^RESET%^\n");
}