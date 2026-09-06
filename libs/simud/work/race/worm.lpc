#include <race.h>
#include <object.h>
#include <const.h>

create() {
   ::create();
   set_bp_flags( BP_HEAD | BP_CHEST | BP_TAIL );
   add_bp( BP_HEAD, "head", 1, 1 );
   add_bp( BP_CHEST, "body", 5, 0 );
   add_bp( BP_TAIL, "tail", 1, -1 );
   set_size( 5 );
   set_food_cost( 0 );	// worms don't eat? shrug
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
   return "crawl";
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 8;
      case "dex": return 4;
      case "con": return 4;
      case "spd": return 4;
      case "wil": return 4;
      case "int": return 4;
      case "emp": return 4;
      case "cha": return 4;
      default: return -1;
   }
}
