#include <const.h>
inherit "/obj/ingredient";

TASTE( "It'd be better in beer." )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 0 );
   set_food_value( 0 ); // Per 1000 units
   set_drink_value( 0 );
   set_weight( 1 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "leaven" );
   set_specific( "the leaven" );
   set_look( "A yeasty, aromatic chunk of damp, floury paste. This leaven can be used to help dough rise or to ferment malt drinks." );
   set_plural( "leaven" );
   set_name( "yeast" );
   set_quantity( 15 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_YEAST ]);
}
