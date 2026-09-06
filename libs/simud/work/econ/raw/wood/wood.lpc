#include <const.h>
inherit "/obj/resource";

NAME( "wood" )
SPECIFIC( "wood" )
DISTANT( "wood" )
PLURAL( "wood" )
ALT_PLURAL( ({ "wood", "units of wood", "board feet of wood" }) )
LOOK( "Some wood. It can be used for building things, or even burning in a fire." )
// The density of pine is about 0.52 g/cm^3. One unit is one liter.
WEIGHT( 520000 )
BULK( 1000000 )
TASTE( "Are you trying to give yourself splinters?" )
UNIT( "board foot" )
UNITS( "board feet" )

ICON( '#', 0x85, LAYER_ITEMS )

int query_fuel() {
   return query_quantity() * 4;
}

int query_fuel_strength() {
   return 200;
}

mapping query_aspects() {
    return ([ C_RAW, C_WOOD ]);
}
