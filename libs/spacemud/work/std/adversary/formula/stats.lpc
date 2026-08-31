/* Do not remove the headers from this file! see /USAGE for more info. */

// stats.c - Generic formula module for basing all combat calculations
//           upon bodystats.
// Iizuka: June 3, 1998.

int query_physical_dmg_stat();
int query_agility_stat();
int query_weapon_class();

int base_chance_to_be_hit()
{
   return 50 - query_agility_stat();
}

int base_chance_to_hit(object target)
{
   return 50 + query_agility_stat();
}

int base_disarm_chance(object target)
{
   return query_physical_dmg_stat() + query_agility_stat() / 2;
}

int disarm_chance(object target)
{
   return base_disarm_chance(target) - target->base_disarm_chance(this_object());
}

int calculate_damage(object weapon, object target)
{
   if (weapon)
      return random(weapon->query_weapon_class() + query_physical_dmg_stat()) + 1;
   else
      return random(query_weapon_class() + query_physical_dmg_stat()) + 1;
}

int chance_to_hit(object weapon, object target)
{
   if (!weapon || weapon == this_object())
      return (target->base_chance_to_be_hit() + base_chance_to_hit(target)) / 2;
   else
      return (target->base_chance_to_be_hit() + weapon->chance_to_hit(target) + base_chance_to_hit(target)) / 3;
}
