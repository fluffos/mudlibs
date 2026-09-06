inherit "/obj/resource";
#include <const.h>

NAME( "salt" )
DISTANT( "salt" )
SPECIFIC( "salt" )
// Setting this causes 'buy salt' to try to purchase everything in stock
//PLURAL( "salt" )
TASTE( "It... tastes... like... SALT." )
LOOK("A solid brick"+(query_quantity()>1?" (or bricks as the case may be)":"")+" of salt. "+(query_quantity()>1?"They are":"It is")+" entirely too huge to be used in any sort of cooking application in this state.")
// Density of NaCl = 2.2 g/cm^3
// Each brick winds up weighing about 1/2 lb
WEIGHT( 220000 )
BULK( 100000 )
UNIT( "brick" )

ICON( '*', 0x88, LAYER_ITEMS )

mapping query_aspects() {
   return ([ C_RAW, C_SALT ]);
}
