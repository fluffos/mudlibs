#include <const.h>
inherit "/obj/ingredient";

TASTE( "~Name ~verbget a milk mustache." )
FOOD_VALUE( 250 ) // per 1000
DRINK_VALUE( 800 )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_weight( 1000 );
   set_bulk( 1000 );
   set_value( 5 );
   set_distant( "milk" );
   set_specific( "the milk" );
   set_look( "Cool and creamy, white and frothy milk." );
   set_plural( "milk" );
   set_name( "milk" );
   set_use_msg( "~Name ~verbchug the cool, frothy milk leaving a nice white mustache." );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_LIQUID, C_MILK ]);
}
