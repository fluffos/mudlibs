// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
int stat_penalty;

void create(int penalty)
{
   buff::create();

   stat_penalty = penalty;

   if (stat_penalty > 0)
   {
      stat_penalty *= -1;
   }

   set_buff_duration(16);
}

int query_stat_penalty()
{
   return stat_penalty;
}

void apply_buff(object target)
{
   my_hook = (: query_stat_penalty :);
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

   if (sizeof(filter_array(all_inventory(target), (: $1->query_effect_name() == "bacta immersion side effects" :) )) == 0)
   {
      tell(target, "%^BOLD%^You feel better as the side effects of bacta immersion wear off.%^RESET%^\n");
   }
}