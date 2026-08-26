// Last edited by deforce on 07-13-2008
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

int health_bonus;

void create(int bonus, int duration)
{
   buff::create();

   health_bonus = bonus;

   set_buff_duration(duration);
}

void apply_buff(object target)
{
   target->heal_us(health_bonus);

   tell(target, "hp: " + target->query_health() + "/" + target->query_max_health() + "    dr: undrugged\n");
}

void remove_buff(object target)
{
   tell(target, "%^BOLD%^You feel the pain come back to you as" + (target->has_buff("/d/buffs/anger") ? "" : " the last of") + " your anger diminishes.%^RESET%^\n");

   target->weaken_us(health_bonus + (target->is_body() ? ((20 - (target->query_for() / 5)) * 2) : 0));
}