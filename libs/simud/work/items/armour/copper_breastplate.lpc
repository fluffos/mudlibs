#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "copper breastplate" )
ALT_NAME( ({ "breastplate", "armour" }) )
DISTANT( "a copper breastplate" )
LOOK( "A polished copper breastplate. It rather effectively protects the chest from most forms of physical punishment short of charging buffalo." )
SPECIFIC( "the copper breastplate" )
PLURAL( "copper breastplates" )
ALT_PLURAL( ({ "breastplates" }) )
TYPE( "armour" )
WEIGHT( 12000 )
TASTE( "It tastes like buffalo." )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["blunt":10,"piercing":-5,"electric":-50]) );
   set_requirement( (["str":12]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts( BP_CHEST | BP_BACK );
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_SHIRT, C_METAL, C_COPPER ]);
}
