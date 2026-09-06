#include <const.h>
#include <object.h>
#include <race.h>

create() {
   ::create();
   set_bp_flags( BT_HUMANOID );
   set_bp_map( DEFAULT_BP_MAP );
   set_size( 20 );
   set_food_cost( 3 );
   set_water_cost( 5 );
   set_hp_per_con( 4 );
   set_min_hp( 25 );
   set_mana_per_emp( 6 );
   set_mana_per_int( 8 );
   set_min_mana( 20 );
   set_end_per_con( 1 );
   set_end_per_will( 2 );
   set_min_end( 5 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 19;
      case "dex": return 21;
      case "con": return 18;
      case "spd": return 20;
      case "wil": return 19;
      case "int": return 21;
      case "emp": return 20;
      case "cha": return 22;
      default: return -1;
   }
}

string *query_mana_affinities() {
	return ({ "spirit", "water", "wind", "earth" });
}
