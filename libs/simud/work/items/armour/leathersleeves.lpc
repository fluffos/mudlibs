#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(70)
NAME( "pair of leather sleeves" )
ALT_NAME( ({"pair of sleeves","leather sleeves","sleeves"}) )
DISTANT( "a pair of leather sleeves" )
LOOK( "Long leather sleeves designed to keep your arms warm, and also protect your arms while shooting a bow.")
SPECIFIC( "the pair of leather sleeves" )
PLURAL( "pairs of leather sleeves" )
TYPE( "bracers" )
WEIGHT( 2700 ) // 2.7 kg =~ 6 lbs
TASTE( "Sleevariffic!" )

void create() {
   ::create();
   set_base_ac(10);
   set_ac_mod( (["ice":10]) );
   set_requirement( (["str":4]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts(BP_ARMS);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_SLEEVES, C_CLOTH, C_LEATHER ]);
}
