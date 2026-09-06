#include <const.h>
inherit "/econ/crop/crop";

NAME( "wheat" )
DISTANT( "a bundle of wheat" )
SPECIFIC( "the wheat" )
LOOK( "A small bundle of bright golden wheat." )
PLURAL( "bundles of wheat" )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 500 )
TASTE( "It tastes like so many possibilities." )
ALT_NAME( ({ "bundle", "bundle of wheat" }) )
ALT_PLURAL( ({ "bundles" }) )

// can't eat raw bundles, must be processed first
void create() {
	::create();
	set_edible(0);
}

mapping query_aspects() {
   return ([ C_FOOD, C_CROP, C_WHEAT, C_GRAIN ]);
}

ICON( '#', 0x83, LAYER_ITEMS )
