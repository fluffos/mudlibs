#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(90)
NAME( "pair of loose leather pants" )
ALT_NAME( ({ "pair of pants", "pair of leather pants", "pants", "leather pants", "loose pants", "loose leather pants"}) )
DISTANT( "a pair of loose leather pants" )
LOOK( "Cured leather, these pants are loose and make no sound as you move.")
SPECIFIC( "the pair of leather pants" )
PLURAL( "pairs of loose leather pants" )
TYPE( "leggings" )
WEIGHT( 3200 ) // 3.2 kg =~ 7 lbs
TASTE( "~Name ~verbwant to visit a leather bar now." )


void create() {
   ::create();
   set_base_ac(10);
   set_ac_mod( (["ice":20]) );
   set_requirement( (["str":6]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_LEGS);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_PANTS, C_CLOTH, C_LEATHER ]);
}
