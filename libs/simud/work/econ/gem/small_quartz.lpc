inherit "/obj/resource";
#include <const.h>

/* Hardness - 7
 * Density  - 2.6 g/cm^3
 * Source : Wikipedia
 */

NAME( "quartz" )
DISTANT( "quartz" )
SPECIFIC( "quartz" )
PLURAL( "small quartz crystals" )
LOOK( "A small, transparent, hexagonal crystal." )
ALT_NAME( ({ "crystal", "small crystal", "small quartz" }) )
ALT_PLURAL( ({ "crystals", "small crystals", "small quartzes", "quartzes" }) )
WEIGHT( 2600 )
BULK( 1000 )
TASTE( "It tastes like frozen sand." )

ICON( '*', 0x15, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_RAW, C_CRYSTAL, C_QUARTZ, C_SMALL ]);
}

string query_unit() {
   return "crystal";
}
