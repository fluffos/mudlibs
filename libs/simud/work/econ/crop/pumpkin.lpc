#include <const.h>
inherit "/econ/crop/crop";

NAME( "pumpkin" )
DISTANT( "a pumpkin" )
SPECIFIC( "the pumpkin" )
LOOK( "A bright orange pumpkin." )
PLURAL( "pumpkins" )
GETTABLE( 1 )
DROPPABLE( 1 )

// average food pumpkins weigh between 5-15lbs (2.2-6.6kg)
// http://pubs.caes.uga.edu/caespubs/pubcd/C780-w.htm
WEIGHT( 4000 )

FOOD_VALUE( 300 )
DRINK_VALUE( 0 )
TASTE( "It tastes like a fuzzy little blue blanket." )

FOOD_BUFF( (["spd":1, "dex":1]) )
FOOD_BUFF_TIME( 10 )

mapping query_aspects() {
   return ([ C_FOOD, C_CROP, C_VEGETABLE, C_PUMPKIN, C_SQUASH ]);
}

// brown with black bg so they show up on the streets of CH ;)
ICON( 'o', 0x03, LAYER_ITEMS )
