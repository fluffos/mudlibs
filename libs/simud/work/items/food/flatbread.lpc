#include <const.h>
inherit "/obj/food";

TASTE( "I wait up all night for you." )
FOOD_VALUE( 180 )
DRINK_VALUE( 0 )

FOOD_BUFF( (["int":2]) )
FOOD_BUFF_TIME( 12 )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 200 );
   set_bulk( 1 );
   set_value( 5 );
   set_distant( "a loaf of flat bread" );
   set_specific( "the loaf of flat bread" );
   set_look( "This is a peice of delightfully chewy flat bread. This would make a great snack although I doubt it will appease your hunger." );
   set_plural( "loaves of flat bread" );
   set_name( "flat bread" );
   set_alt_name( "bread" );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD, C_BREAD, C_FLATBREAD ]);
}
