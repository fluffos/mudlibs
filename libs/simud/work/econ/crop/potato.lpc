#include <const.h>
inherit "/econ/crop/crop";

NAME( "potato" )
DISTANT( "a potato" )
SPECIFIC( "the potato" )
LOOK( "A firm, brown potato." )
PLURAL( "potatoes" )
GETTABLE( 1 )
DROPPABLE( 1 )

// nutritiondata.com - 2-1/4" to 3-1/4" dia, flesh and skin
WEIGHT( 213 )

FOOD_VALUE( 100 )
DRINK_VALUE( 0 )
TASTE( "It tastes like dirt." )

// super ultra long lasting
FOOD_BUFF( (["con":1, "hunger":-2]) )
FOOD_BUFF_TIME( 10 )

mapping query_aspects() {
   return ([ C_FOOD, C_CROP, C_VEGETABLE, C_POTATO ]);
}

ICON( 'o', 0x83, LAYER_ITEMS )
