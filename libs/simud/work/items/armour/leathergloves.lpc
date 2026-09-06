#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(30)
NAME( "pair of leather gloves" )
ALT_NAME( ({"pair of gloves","gloves","leather gloves"}) )
DISTANT( "a pair of leather gloves" )
LOOK( "Soft leather gloves which warm your hands and look really cool.")
SPECIFIC( "the pair of leather gloves" )
PLURAL( "pairs of leather gloves" )
TYPE( "gauntlets" )
WEIGHT( 680 ) // .68 kg =~ 1.5 lbs
TASTE( "They taste like leather." )

void create() {
   ::create();
   set_base_ac(5);
   set_ac_mod( (["ice":10]) );
   set_requirement( (["str":2]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_HANDS);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_GLOVES, C_CLOTH, C_LEATHER ]);
}
