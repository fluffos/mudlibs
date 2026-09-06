#include <const.h>
inherit "/obj/ingredient";

TASTE( "It would taste better scrambled, that's for sure." )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_food_value( 250 ); // Per 1000 units
   set_drink_value( 150 ); // Per 1000 units
   set_weight( 1400 );
   set_bulk( 1000 );
   set_value( 0 );
   set_distant( "egg" );
   set_specific( "the egg" );
   set_look( "Raw egg. It's runny and goopy." );
   set_plural( "egg" );
   set_name( "egg" );
   set_use_msg( "~Name ~verbslurp down the raw egg." );
   set_quantity( 30 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD, C_LIQUID, C_EGG, C_CRACKEDEGG ]);
}
