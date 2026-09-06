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
   set_hp_per_con( 4 );
   set_min_hp( 40 );
   set_mana_per_emp( 1 );
   set_mana_per_int( 1 );
   set_min_mana( 10 );
   set_end_per_con( 1 );
   set_end_per_will( 2 );
   set_min_end( 5 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 18;
      case "dex": return 20;
      case "con": return 18;
      case "spd": return 20;
      case "wil": return 18;
      case "int": return 16;
      case "emp": return 20;
      case "cha": return 14;
      default: return -1;
   }
}
