#include <const.h>
#include <object.h>
#include <race.h>

void create() {
   ::create();
   set_bp_flags( BT_HUMANOID );
   set_bp_map( DEFAULT_BP_MAP );
   set_size( 20 );
   set_food_cost( 4 );
   set_water_cost( 4 );
   set_hp_per_con( 5 );
   set_min_hp( 25 );
   set_mana_per_emp( 8 );
   set_mana_per_int( 5 );
   set_min_mana( 10 );
   set_end_per_con( 2 );
   set_end_per_will( 1 );
   set_min_end( 5 );
}

string *query_mana_affinities() {
	return ({ "earth", "spirit", "water" });
}
