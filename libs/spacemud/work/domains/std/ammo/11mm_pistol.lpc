/* Do not remove the headers from this file! see /USAGE for more info. */

inherit AMMUNITION;

void setup()
{
   set_id("11mm bullet", "ammo", "clip");
   set_long("A clip of 11 mm standard high-velocity pistol ammo.");
   set_combat_messages("combat-firearm");
   set_damage_type("force");
   set_skill_used("combat/ranged/pistol");
   set_charges(8);
   set_ammo_type("11mm bullets");
   set_weapon_class(12);
   set_destruct_on_spent();
   set_value(24);
}

string alt_weapon()
{
   switch (random(3))
   {
   case 0:
      return "11mm bullet";
   case 1:
      return "pistol bullet";
   case 2:
      return "high-velocity round";
   }
}
