// Last edited by deforce on 03-10-2010
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

int damage_penalty;
int agility_penalty;
function my_hook;

void create(int dmg_penalty, int agi_penalty, int dur_penalty)
{
   buff::create();

   damage_penalty = dmg_penalty;
   agility_penalty = agi_penalty;

   set_buff_duration(dur_penalty);
}

int query_agility_penalty()
{
   return agility_penalty * -1;
}

void apply_buff(object target)
{
   my_hook = (: query_agility_penalty :);
   target->add_damage_bonus(damage_penalty * -1);
   target->add_hook("agi_bonus", my_hook);
   target->refresh_stats();

   tell(target, "%^BOLD%^%^RED%^You feel weak as your rage subsides.%^RESET%^\n");
}

void remove_buff(object target)
{
   target->add_damage_bonus(damage_penalty);
   target->remove_hook("agi_bonus", my_hook);
   target->refresh_stats();

   tell(target, "%^BOLD%^You no longer feel weak without your rage.%^RESET%^\n");
}