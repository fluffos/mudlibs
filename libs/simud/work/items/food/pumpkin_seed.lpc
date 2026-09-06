#include <const.h>
inherit "/obj/food";

TASTE( "It tastes like roasted buttery goodness." )
FOOD_VALUE( 5 )
DRINK_VALUE( 0 )

// salty: +1 drink consumption per tick
// pumpkin: +5 ac versus cold and blunt damage
// buttery: +1 empathy
FOOD_BUFF( (["thirst": 1, "ac cold": 5, "ac blunt": 5, "emp": 1]) )
// only lasts 2 minutes
FOOD_BUFF_TIME( 2 )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 1 );
   set_bulk( 1 );
   set_distant( "a roast pumpkin seed" );
   set_specific( "the roast pumpkin seed" );
   set_look( "A roast pumpkin seed." );
   set_plural( "roast pumpkin seeds" );
   set_name( "seed" );
   set_alt_name( ({"pumpkin seed", "roast pumpkin seed"}) );
   set_alt_plural( ({"pumpkin seeds", "seeds"}) );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_FOOD ]);
}
