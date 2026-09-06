#include <const.h>
inherit "/obj/ingredient";

TASTE( "It tastes like hyperactivity waiting to happen." )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_food_value( 2 ); // Per 1000 units
   set_height( 1 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "sugar" );
   set_specific( "the sugar" );
   set_look( "White beet sugar." );
   set_plural( "sugar" );
   set_name( "sugar" );
   set_use_msg( "~Name ~verbeat some sugar." );
   set_quantity( 10 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD, C_SUGAR ]);
}
