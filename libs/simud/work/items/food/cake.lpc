#include <const.h>
inherit "/obj/food";

TASTE( "It must be ~poss birthday!" )
FOOD_VALUE( 100 )
DRINK_VALUE( 0 )

FOOD_BUFF( (["cha":2, "hunger":-1]) )
FOOD_BUFF_TIME( 10 )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 1000 );
   set_value( 50 );
   set_distant( "a cake" );
   set_specific( "the cake" );
   set_look( "A freshly baked cake with deluxe chocolate frosting." );
   set_plural( "cakes" );
   set_name( "cake" );
   set_alt_name( "chocolate cake" );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD ]);
}
