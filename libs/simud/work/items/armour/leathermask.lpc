#include <const/raceconst.h>
#include <const.h>
inherit "/battle/armour";

NAME( "stiff leather mask" )
GETTABLE( 1 )
DROPPABLE( 1 )
ALT_NAME( ({ "mask", "leather mask" }) )
DISTANT( "a stiff leather mask" )
LOOK( "Made of cured and hardened leather, this mask covers almost your entire face. It looks very imposing, as it is shaped like the head of a wolf.")
SPECIFIC( "the leather mask" )
PLURAL( "stiff leather masks" )
TYPE( "helmet" )
WEIGHT( 230 ) // 230 g =~ .5 lbs
VALUE(45)
TASTE( "What are you, thick?" )

void create() {
   ::create();
   set_base_ac(10);
   set_ac_mod( (["ice":10]) );
   set_requirement( (["str":5]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_HEAD);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_HEADGEAR, C_CLOTH, C_LEATHER ]);
}
