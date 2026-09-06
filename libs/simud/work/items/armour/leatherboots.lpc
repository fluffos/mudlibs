#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(50)
NAME( "leather boots" )
ALT_NAME( ({"boots"}) )
DISTANT( "a pair of leather boots" )
LOOK( "Fashioned of soft leather, these boots warm your feet but do little else...")
SPECIFIC( "the leather boots" )
PLURAL( "pairs of leather boots" )
TYPE( "boots" )
WEIGHT( 450 ) // .45 kg =~ 1 lb
TASTE( "They taste like feet. Ewwww..." )

void create() {
   ::create();
   set_base_ac(5);
   set_ac_mod( (["ice":10]) );
   set_requirement( (["str":2]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts(BP_FEET);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_SHOES, C_METAL, C_IRON, C_CLOTH, C_LEATHER ]);
}
