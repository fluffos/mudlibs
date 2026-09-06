#include <const.h>
inherit "/obj/ingredient";

TASTE( "It remings ~Name of childhood." )
FOOD_VALUE( 300 ) // per 1000
DRINK_VALUE( 750 )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_weight( 1000 );
   set_bulk( 1000 );
   set_value( 5 );
   set_distant( "chocolate milk" );
   set_specific( "the chocolate milk" );
   set_look( "Sludgy, brown, sweet milk." );
   set_plural( "chocolate milk" );
   set_name( "milk" );
   set_use_msg( "~Name ~verbchug the thick, sludgy chocolate milk before it dawns on ~obje that it's probably just dirty milk.  Gross!" );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_LIQUID, C_MILK ]);
}
