#include <race.h>
#include <object.h>
#include <const.h>

// Should work for flying, stinging insects, but we'll just call it wasp for
// now since that's the only one planned for a while

create() {
   ::create();
   set_bp_flags( BP_HEAD | BP_CHEST | BP_BACK | BP_ARMS | BP_TAIL );
   add_bp( BP_HEAD, "head", 2, 2 );
   add_bp( BP_CHEST, "chest", 3, 1 );
   add_bp( BP_BACK, "back", 4, 0 );
   add_bp( BP_LARM, "left wing", 3, 0 );
   add_bp( BP_RARM, "right wing", 3, 0 );
   add_bp( BP_TAIL, "stinger", 2, -1 );
   set_size( 5 );
   set_food_cost( 1 );
   set_water_cost( 1 );
   set_hp_per_con( 5 );
   set_min_hp( 5 );
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
      case "str": return 4;
      case "dex": return 20;
      case "con": return 8;
      case "spd": return 24;
      case "wil": return 4;
      case "int": return 4;
      case "emp": return 4;
      case "cha": return 4;
      default: return -1;
   }
}
