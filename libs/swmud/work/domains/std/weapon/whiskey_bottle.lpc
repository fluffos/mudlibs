#include <combat_modules.h>

inherit WEAPON;

void setup()
{
   set_id("whiskey bottle", "bottle");
   set_adj("broken");
   set_long("This broken whiskey bottle still smells of whiskey. Who would use such a weapon?");
   set_weapon_class(7);
   set_disarm_bonus(2);
   set_damage_bonus(2);
   set_weight(2);
   set_skill_used("combat/melee/improv");
   set_salvageable((["metal":100]));
}

int query_value()
{
   return 10 + random(10);
}
