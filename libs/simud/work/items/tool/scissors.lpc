inherit "/items/weapon/dagger";

NAME( "scissors" )
LOOK( "A fancy pair of copper scissors." )
DISTANT( "a pair of scissors" )
SPECIFIC( "the pair of scissors" )
PLURAL( "pairs of scissors" )
TYPE( "weapon" )
WEAPON_TYPE( "dagger" )
TASTE( "It tastes like blood. Wait, that's your tongue." )

WEIGHT( 200 ) // .5lbs

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":3]) );
   set_requirement( (["dex":8]) );
}

mapping query_aspects() {
   return ([ C_SCISSORS, C_METAL, C_COPPER ]);
}
