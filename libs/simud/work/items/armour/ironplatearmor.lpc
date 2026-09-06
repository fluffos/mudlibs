#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(3500)
NAME( "plate armour" )
ALT_NAME( ({"armor", "armour", "suit", "suit of armour", "suit of armor", "plate armour", "plate armor", "iron plate", "iron armour", "iron armour", "iron plate armour"}) )
DISTANT( "a suit of iron plate armour" )
LOOK( "An immensely heavy piece of armour, this suit covers your chest and back quite well. In fact, while wearing it, you can't see any exposed skin between your waist and neck! Unfortunately, it restricts movement a bit.")
SPECIFIC( "the iron plate armour" )
PLURAL( "suits of iron plate armour" )
TYPE( "armour" )
WEIGHT( 18000 ) // 18 kg =~ 40 lbs
TASTE( "It tastes heavy." )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["slashing":10,"electric":-40]) );
   set_requirement( (["str":17]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts(BP_TORSO);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_SHIRT, C_METAL, C_IRON ]);
}
