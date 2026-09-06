#include <const.h>
#include <object.h>
#include <race.h>

create() {
   ::create();
   set_bp_flags( BT_HUMANOID );
   set_bp_map( DEFAULT_BP_MAP );
   set_size( 10 );
   set_food_cost( 5 );
   set_water_cost( 3 );
   set_hp_per_con( 4 );
   set_min_hp( 20 );
   set_mana_per_emp( 5 );
   set_mana_per_int( 3 );
   set_min_mana( 10 );
   set_end_per_con( 1 );
   set_end_per_will( 2 );
   set_min_end( 10 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 18;
      case "dex": return 22;
      case "con": return 20;
      case "spd": return 21;
      case "wil": return 20;
      case "int": return 20;
      case "emp": return 20;
      case "cha": return 20;
      default: return -1;
   }
}

string *query_mana_affinities() {
	return ({ "wind", "earth", "fire" });
}
