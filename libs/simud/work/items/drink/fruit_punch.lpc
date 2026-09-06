#include <const.h>
inherit "/obj/ingredient";

TASTE( "It tastes like amoxycillin." )
FOOD_VALUE( 100 ) // per 1000
DRINK_VALUE( 750 )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_weight( 1000 );
   set_bulk( 1000 );
   set_value( 5 );
   set_distant( "fruit punch" );
   set_specific( "the fruit punch" );
   set_look( "Purple-red fruity goodness." );
   set_plural( "fruit punch" );
   set_name( "punch" );
   set_use_msg( "~Name ~verbtake a long swig of ~targ." );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_LIQUID, C_FRUIT ]);
}
