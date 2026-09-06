inherit "/econ/crop/crop";

NAME( "sugar beet" )
DISTANT( "a sugar beet" )
SPECIFIC( "the sugar beet" )
LOOK( "A large yellowish root, useful in sugar production." )
PLURAL( "sugar beets" )
ALT_NAME( ({ "beet" }) )
ALT_PLURAL( ({ "beets" }) )
GETTABLE( 1 )
DROPPABLE( 1 )

// wikipedia
// "large 1-2kg storage root whose dry mass is 15-20% sucrose by weight"
// This means we produce between 225 and 300 sugar per beet. 250 sounds like
// a wonderful number to me.
WEIGHT( 1500 )

FOOD_VALUE( 50 )
DRINK_VALUE( 0 )
TASTE( "It tastes waaay too sweet for its own good." )

FOOD_BUFF( (["dex":-3, "spd":2]) )
FOOD_BUFF_TIME( 5 )

mapping query_aspects() {
   return ([ C_FOOD, C_CROP, C_VEGETABLE, C_BEET, C_SUGAR_BEET ]);
}

ICON( 'o', 0x8B, LAYER_ITEMS )
