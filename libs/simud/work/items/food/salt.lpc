#include <const.h>
inherit "/obj/ingredient";

TASTE( "It tastes like independence from imperialism." )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_food_value( 2 ); // Per 1000 units
   set_drink_value( -1 );
   set_height( 1 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "salt" );
   set_specific( "the salt" );
   set_look( "White sea salt, flecked with other colors." );
   set_plural( "salt" );
   set_name( "salt" );
   set_use_msg( "~Name ~verbeat some salt." );
   set_quantity( 10 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD, C_SALT ]);
}
