/* Do not remove the headers from this file! see /USAGE for more info. */

//Example rapier that modified a skill when wielded, and removes it again when unwielded.
//Notice custom property "skillfull".

inherit SWORD;

void wielded()
{
   environment()->add_skill_bonus("combat/defense/stance",200);
}

void unwielded()
{
   environment()->remove_skill_bonus("combat/defense/stance",200);
}

void setup()
{
   set_weapon_class(8);
   set_id("rapier");
   set_weight(1.0);
   set_value(25);
   set_skill_used("combat/melee/blade");
   set_skill_restriction("combat/melee/blade", 2);
   set_skill_restriction_message("The rapier feels foreign in $p hand. $N $vwield it like $n would wield a stick.");
   add_combat_message("miss", "$N $vtake an untrained swipe at $t, but only $vsucceed in losing $p footing.");
   add_property("skillfull");
}
