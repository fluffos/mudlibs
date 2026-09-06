#include <const.h>
inherit "/econ/crop/crop";

NAME( "corn" )
DISTANT( "an ear of corn" )
SPECIFIC( "the corn" )
LOOK( "A juicy yellow and white ear of corn." )
PLURAL( "ears of corn" )
GETTABLE( 1 )
DROPPABLE( 1 )

// nutritiondata.com - 6-3/4" to 7-1/2" long, yellow, sweet
WEIGHT( 90 )
		
FOOD_VALUE( 100 )
DRINK_VALUE( 0 )
TASTE( "It tastes like little golden nuggets of joy." )
ALT_NAME( ({ "maize", "ear", "ear of corn" }) )
ALT_PLURAL( ({ "ears" }) )

// super ultra long lasting
FOOD_BUFF( (["con":1, "dex":1, "hunger":-1]) )
FOOD_BUFF_TIME( 7 )

mapping query_aspects() {
   return ([ C_FOOD, C_CROP, C_VEGETABLE, C_CORN, C_GRAIN ]);
}

ICON( '8', 0x8B, LAYER_ITEMS )
