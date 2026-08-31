/* Do not remove the headers from this file! see /USAGE for more info. */

inherit WEAPON;
inherit M_THROWABLE;


string colour;

void setup(string c)
{
   colour=c;
   set_adj(colour);
   set_id("stick");
   set_weapon_class(2);
   set_damage_type("bludgeon");
   set_long("A simple stick coloured "+colour+".");
   set_in_room_desc("A "+colour+" stick is lying on the ground.");
   set_weight(1);
   set_value(2);
   set_skill_used("combat/melee/club");
   set_combat_messages("combat-bludgeon");
   set_salvageable((["wood":100]));
}

mixed *setup_args()
{
   return ({colour});
}

//This hints can be read by cloning the stick and doing 'hints stick'.
string query_hint(int level)
{
   return "Yes, it's a stick.";
}