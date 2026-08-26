// Last edited by deforce on 03-10-2010
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

int damage_bonus;
int agility_bonus;
int damage_penalty;
int agility_penalty;
int penalty_duration;
function my_hook;

void create(int dmg_bonus, int agi_bonus, int dur_bonus, int dmg_penalty, int agi_penalty, int dur_penalty)
{
   buff::create();

   damage_bonus = dmg_bonus;
   agility_bonus = agi_bonus;
   damage_penalty = dmg_penalty;
   agility_penalty = agi_penalty;
   penalty_duration = dur_penalty;

   set_buff_duration(dur_bonus);
}

int query_agility_bonus()
{
   return agility_bonus;
}

void apply_buff(object target)
{
   my_hook = (: query_agility_bonus :);
   target->add_damage_bonus(damage_bonus);
   target->add_hook("agi_bonus", my_hook);
   target->refresh_stats();

   target->other_action("$N $vare surrounded by a steady, red glow.\n");
   tell(target, "You feel the Force flow through you, fueling your rage.\n");
}

void remove_buff(object target)
{
   target->add_damage_bonus(damage_bonus * -1);
   target->remove_hook("agi_bonus", my_hook);

   target->other_action("The red glow around $N fades away.\n");
   tell(target, "%^BOLD%^Your rage is no longer being fueled by the Force.%^RESET%^\n");

   if ((damage_penalty > 0) && (agility_penalty > 0))
   {
      load_object("/d/buffs/force_rage_penalty");
      target->add_buff(new("/d/buffs/force_rage_penalty", damage_penalty, agility_penalty, penalty_duration));
   }
   else
   {
      target->refresh_stats();
   }
}