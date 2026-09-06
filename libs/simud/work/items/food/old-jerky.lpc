/**
 *
 * This file has been deprecated by the real jerky that is actually crafted from
 * raw meat by the players ;)
 *
 */

#include <const.h>
inherit "/obj/food";

TASTE( "It tastes like it came from a truck stop." )
// TODO: Fix me, please!

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_food_value( 30 );
   set_drink_value( 0 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 150 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "a strip of jerky" );
   set_specific( "the jerky" );
   set_look( "Nummy authentic dried cow flesh. Packed with protien and "+
             "guaranteed to keep you from starving to death when you get "+
             "lost in the middle of the wolves... I mean woods." );
   set_plural( "strips of jerky" );
   set_name( "jerky" );
   set_alt_name( ({"meat", "strip"}) );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD, C_MEAT, C_BEEF]);
}
