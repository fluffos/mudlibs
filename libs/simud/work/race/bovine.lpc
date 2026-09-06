#include <race.h>
#include <object.h>
#include <const.h>

// Hooved quadropeds such as deer, cows, goats, pigs, etc... are all
// fundamentally the same animal. Thus, I declare them to be cows.

create() {
   ::create();
   set_bp_flags( BT_QUADRUPED | BP_TAIL );
   add_bp( BP_HEAD, "head", 2, 2 );
   add_bp(  BP_NECK, "neck", 1, 2 );
   add_bp(  BP_CHEST, "chest", 3, 1 );
   add_bp(  BP_GROIN, "loins", 0, 1 );
   add_bp(  BP_BACK, "back", 4, 0 );
   add_bp(  BP_TAIL, "tail", 3, -2 );
   add_bp(  BP_LLEG, "front left leg", 2, -1 );
   add_bp(  BP_RLEG, "front right leg", 2, -1 );
   add_bp(  BP_LFOOT, "front left hoof", 1, -2 );
   add_bp(  BP_RFOOT, "front right hoof", 1, -2 );
   add_bp(  BP_LLEG2, "rear left leg", 1, -1 );
   add_bp(  BP_RLEG2, "rear right leg", 1, -1 );
   add_bp(  BP_LFOOT2, "rear left hoof", 0, -2 );
   add_bp(  BP_RFOOT2, "rear right hoof", 0, -2 );
   set_size( 30 );
   set_food_cost( 4 );
   set_water_cost( 4 );
   set_hp_per_con( 8 );
   set_min_hp( 35 );
   set_mana_per_emp( 1 );
   set_mana_per_int( 0 );
   set_min_mana( 0 );
   set_end_per_con( 4 );
   set_end_per_will( 2 );
   set_min_end( 10 );
}

// let my moo-cows eat!
int query_can_graze() { return 1; }

int query_stat_max(string stat) {
   switch (stat) {
      case "str": return 26;
      case "dex": return 10;
      case "con": return 22;
      case "spd": return 10;
      case "wil": return 10;
      case "int": return 4;
      case "emp": return 10;
      case "cha": return 4;
      default: return -1;
   }
}
