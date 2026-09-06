#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(160)
NAME( "pair of iron bracers" )
ALT_NAME( ({"pair of bracers","iron bracers","bracers"}) )
DISTANT( "a pair of iron bracers" )
LOOK( "Two plates of metal curved to fit your wrist and held on with soft leather straps.")
SPECIFIC( "the pair of iron bracers" )
PLURAL( "pairs of iron bracers" )
TYPE( "bracers" )
WEIGHT( 900 ) // .9 kg =~ 2 lbs
TASTE( "~Name ~verbdetect wonderful ulnar support." )

void create() {
   ::create();
   set_base_ac(30);
   set_ac_mod( (["slashing":40,"electric":-20]) );
   set_requirement( (["str":3]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(5);
   set_body_parts(BP_WRISTS);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_BRACERS, C_METAL, C_IRON, C_CLOTH, C_LEATHER ]);
}
