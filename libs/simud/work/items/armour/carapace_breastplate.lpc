#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "carapace breastplate" )
ALT_NAME( ({ "breastplate", "armour" }) )
DISTANT( "a carapace breastplate" )
LOOK( "A piece of chest armour fashioned from a number of large shells of insect or similar origin. It is light, but strong for its weight and covers its wearer from the neck to the groin." )
SPECIFIC( "the carapace breastplate" )
PLURAL( "carapace breastplates" )
ALT_PLURAL( ({ "breastplates" }) )
TYPE( "armour" )
WEIGHT( 8000 )
TASTE( "It tastes like dried bug guts." )

void create() {
   ::create();
   set_base_ac(30);
   set_ac_mod( (["blunt":10,"piercing":-25]) );
   set_requirement( (["str":8]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts( BP_CHEST | BP_BACK | BP_NECK | BP_GROIN );
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_SHIRT, C_CARAPACE ]);
}
