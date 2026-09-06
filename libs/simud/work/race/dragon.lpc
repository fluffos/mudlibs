#include <const.h>
#include <object.h>
#include <race.h>

create() {
   ::create();
   set_bp_flags( BT_QUADRUPED | BP_TAIL | BP_ARMS );
   add_bp( BP_HEAD, "head", 2, 2 );
   add_bp( BP_NECK, "neck", 1, 2 );
   add_bp( BP_CHEST, "chest", 3, 1 );
   add_bp( BP_GROIN, "loins", 0, 1 );
   add_bp( BP_BACK, "back", 4, 0 );
   add_bp( BP_TAIL, "tail", 3, -2 );
   add_bp( BP_LARM, "left wing", 5, -1 );
   add_bp( BP_RARM, "right wing", 5, -1 );
   add_bp( BP_LLEG, "front left leg", 2, -1 );
   add_bp( BP_RLEG, "front right leg", 2, -1 );
   add_bp( BP_LFOOT, "front left leg", 1, -2 );
   add_bp( BP_RFOOT, "front right leg", 1, -2 );
   add_bp( BP_LLEG2, "rear left leg", 1, -1 );
   add_bp( BP_RLEG2, "rear right leg", 1, -1 );
   add_bp( BP_LFOOT2, "rear left leg", 0, -2 );
   add_bp( BP_RFOOT2, "rear right leg", 0, -2 );
   set_size( 90 );
   set_food_cost( 10 );
   set_water_cost( 10 );
   set_hp_per_con( 125 );
   set_min_hp( 1000 );
   set_mana_per_emp( 25 );
   set_mana_per_int( 50 );
   set_min_mana( 100 );
   set_end_per_con( 50 );
   set_end_per_will( 25 );
   set_min_end( 500 );
}

string query_default_movement_type() {
   return "fly";
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 30;
      case "dex": return 25;
      case "con": return 25;
      case "spd": return 15;
      case "wil": return 30;
      case "int": return 25;
      case "emp": return 25;
      case "cha": return 25;
      default: return -1;
   }
}
