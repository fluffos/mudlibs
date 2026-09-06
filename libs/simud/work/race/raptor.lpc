#include <race.h>
#include <object.h>
#include <const.h>

// Predatory birds

create() {
   ::create();
   set_bp_flags( BP_HEAD | BP_CHEST | BP_BACK | BP_ARMS | BP_FEET );
   add_bp( BP_HEAD, "head", 2, 2 );
   add_bp( BP_CHEST, "chest", 3, 1 );
   add_bp( BP_BACK, "back", 4, 0 );
   add_bp( BP_LARM, "left wing", 6, 0 );
   add_bp( BP_RARM, "right wing", 6, 0 );
   add_bp( BP_LFOOT, "left talon", 1, -1 );
   add_bp( BP_RFOOT, "right talon", 1, -1 );
   set_size( 7 );
   set_food_cost( 3 );
   set_water_cost( 2 );
   set_hp_per_con( 8 );
   set_min_hp( 20 );
   set_mana_per_emp( 1 );
   set_mana_per_int( 0 );
   set_min_mana( 0 );
   set_end_per_con( 4 );
   set_end_per_will( 2 );
   set_min_end( 10 );
}

string query_default_movement_type() {
   return "fly";
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 10;
      case "dex": return 24;
      case "con": return 10;
      case "spd": return 26;
      case "wil": return 4;
      case "int": return 10;
      case "emp": return 10;
      case "cha": return 4;
      default: return -1;
   }
}
