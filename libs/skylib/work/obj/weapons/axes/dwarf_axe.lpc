#include "move_failures.h";
inherit WEAPON_OBJ;

void setup(){

/* DESCRIPTIONS */

   set_name("axe");
   set_short("dwarven axe");
   set_long("A finely crafted axe of dwarven steel.\n");
   set_main_plural("dwarven axes");
   add_plural("axes");
   add_adjective("dwarven");

/* STATS */

   new_weapon(1000);
   set_damage_chance(5);
   add_attack( "chop", 0, ({ 50, 2, 50 }), "sharp", "sharp", 0 );
   set_weight(140);
   adjust_money(9, "silver");
   add_property("dwarven axe", 1);
}
