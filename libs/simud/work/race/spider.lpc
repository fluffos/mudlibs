#include <race.h>
#include <object.h>
#include <const.h>

create() {
   ::create();
   set_bp_flags( BT_INSECT );
   add_bp( BP_HEAD, "head", 1, 2 );
   add_bp( BP_CHEST, "chest", 2, 1 );
   add_bp( BP_BACK, "back", 2, 0 );
   add_bp( BP_LLEG, "left front leg", 1, -1 );
   add_bp( BP_RLEG, "right front leg", 1, -1 );
   add_bp( BP_LLEG2, "left middle leg", 2, -1 );
   add_bp( BP_RLEG2, "right middle leg", 2, -1 );
   add_bp( BP_LLEG3, "left rear leg", 1, -1 );
   add_bp( BP_RLEG3, "right rear leg", 1, -1 );
   set_size( 10 );
   set_food_cost( 1 );
   set_water_cost( 1 );
   set_hp_per_con( 10 );
   set_min_hp( 5 );
   set_mana_per_emp( 1 );
   set_mana_per_int( 0 );
   set_min_mana( 0 );
   set_end_per_con( 4 );
   set_end_per_will( 2 );
   set_min_end( 10 );
}

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 12;
      case "dex": return 16;
      case "con": return 12;
      case "spd": return 16;
      case "wil": return 4;
      case "int": return 8;
      case "emp": return 10;
      case "cha": return 4;
      default: return -1;
   }
}
