#include <const.h>
inherit "/obj/food";

TASTE( "Doughy." )
FOOD_VALUE( 250 )
DRINK_VALUE( 0 )

FOOD_BUFF( (["emp":1, "int":1]) )
FOOD_BUFF_TIME( 15 )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 200 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "a loaf of bread" );
   set_specific( "the loaf of bread" );
   set_look( "A very light and fluffy loaf of bread.  Mmm, with a little butter this could make a nice treat." );
   set_plural( "loaves of bread" );
   set_name( "bread" );
   set_alt_name( "loaf" );
/* } OBJEDIT */
}

mapping query_aspects() {
   return ([ C_FOOD, C_BREAD, C_WHEATBREAD ]);
}
