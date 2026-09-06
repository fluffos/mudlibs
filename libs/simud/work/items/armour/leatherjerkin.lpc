#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(120)
NAME( "leather jerkin" )
ALT_NAME( ({ "jerkin" }) )
DISTANT( "a leather jerkin" )
LOOK( "A fitted leather jerkin, full of pouches and lined with soft fur.")
SPECIFIC( "the leather jerkin" )
PLURAL( "leather jerkins" )
ALT_PLURAL( ({ "jerkins" }) )
TYPE( "armour" )
WEIGHT( 5500 ) // 5.5 kg =~ 12 lbs
TASTE( "It tastes like pockets." )

void create() {
   ::create();
   set_base_ac(10);
   set_ac_mod( (["ice":20]) );
   set_requirement( (["str":8]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_TORSO | BP_ARMS);
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_JERKIN, C_CLOTH, C_LEATHER ]);
}
