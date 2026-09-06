#include <const.h>
#include <object.h>
#include <race.h>

create() {
   ::create();
   set_bp_flags( BT_HUMANOID );
   set_bp_map( DEFAULT_BP_MAP );
   set_size( 25 );
   set_food_cost( 6 );
   set_water_cost( 4 );
   set_hp_per_con( 7 );
   set_min_hp( 35 );
   set_mana_per_emp( 1 );
   set_mana_per_int( 1 );
   set_min_mana( 0 );
   set_end_per_con( 4 );
   set_end_per_will( 1 );
   set_min_end( 10 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 22;
      case "dex": return 20;
      case "con": return 20;
      case "spd": return 20;
      case "wil": return 20;
      case "int": return 19;
      case "emp": return 18;
      case "cha": return 20;
      default: return -1;
   }
}

string *query_mana_affinities() {
	return ({ "water", "chaos", "earth" });
}
