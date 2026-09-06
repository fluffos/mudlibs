#include <const.h>
#include <object.h>
#include <race.h>

create() {
   ::create();
   set_bp_flags( BT_HUMANOID );
   set_bp_map( DEFAULT_BP_MAP );
   set_size( 10 );
   set_food_cost( 4 );
   set_water_cost( 4 );
   set_hp_per_con( 5 );
   set_min_hp( 25 );
   set_mana_per_emp( 9 );
   set_mana_per_int( 2 );
   set_min_mana( 15 );
   set_end_per_con( 1 );
   set_end_per_will( 2 );
   set_min_end( 5 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 19;
      case "dex": return 20;
      case "con": return 20;
      case "spd": return 21;
      case "wil": return 21;
      case "int": return 18;
      case "emp": return 22;
      case "cha": return 19;
      default: return -1;
   }
}

string *query_mana_affinities() {
	return ({ "spirit", "fire", "lightning", "chaos" });
}
