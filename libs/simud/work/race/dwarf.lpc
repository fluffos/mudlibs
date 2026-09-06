#include <const.h>
#include <object.h>
#include <race.h>

void create() {
   ::create();
   set_bp_flags( BT_HUMANOID );
   set_bp_map( DEFAULT_BP_MAP );
   set_size( 15 );
   set_food_cost( 4 );
   set_water_cost( 4 );
   set_hp_per_con( 6 );
   set_min_hp( 30 );
   set_mana_per_emp( 1 );
   set_mana_per_int( 1 );
   set_min_mana( 0 );
   set_end_per_con( 3 );
   set_end_per_will( 2 );
   set_min_end( 10 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 21;
      case "dex": return 19;
      case "con": return 22;
      case "spd": return 19;
      case "wil": return 21;
      case "int": return 20;
      case "emp": return 20;
      case "cha": return 18;
   }
   return -1;
}

string *query_mana_affinities() {
	return ({ "fire", "earth", "order", "spirit" });
}
