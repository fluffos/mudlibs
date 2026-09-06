#include <race.h>
#include <object.h>
#include <const.h>

// Generic flying critters, specifically herbivorous birds.

void create() {
   ::create();
   set_bp_flags( BP_HEAD | BP_CHEST | BP_BACK | BP_ARMS );
   add_bp( BP_HEAD, "head", 2, 2 );
   add_bp( BP_CHEST, "chest", 3, 1 );
   add_bp( BP_BACK, "back", 4, 0 );
   add_bp( BP_LARM, "left wing", 5, 0 );
   add_bp( BP_RARM, "right wing", 5, 0 );
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

// duckies can eat grass
int query_can_graze() { return 1; }

string query_default_movement_type() {
   return "fly";
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 4;
      case "dex": return 26;
      case "con": return 4;
      case "spd": return 24;
      case "wil": return 4;
      case "int": return 4;
      case "emp": return 10;
      case "cha": return 10;
      default: return -1;
   }
   return -1;
}
