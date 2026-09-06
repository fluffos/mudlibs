#include <const.h>
inherit "/obj/food";

TASTE( "It tastes like grandmotherly love." )
FOOD_VALUE( 10 )
DRINK_VALUE( 0 )

FOOD_BUFF( (["hunger":-1]) )
FOOD_BUFF_TIME( 4 )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 1 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "a cookie" );
   set_specific( "the cookie" );
   set_look( "A freshly baked chocolate chip cookie." );
   set_plural( "cookies" );
   set_name( "cookie" );
   set_alt_name( "chocolate cookie" );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD ]);
}
