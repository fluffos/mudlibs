#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "iron helm" )
ALT_NAME( ({"helmet","helm","Iron Helm"}) )
DISTANT( "an iron helm" )
LOOK( "Made completely of iron, this helm is a good deterrence for blades, but does not provide much defense from stabbing weapons. This is the perfect helmet for the thrifty warrior.")
SPECIFIC( "the iron helm" )
PLURAL( "iron helms" )
ALT_PLURAL( ({ "helms", "helmets" }) )
TYPE( "helmet" )
WEIGHT( 1400 ) // 1.4 kg =~ 3 lbs
TASTE( "It tastes like dandruff." )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["edged":10, "blunt":10,"electric":-20]) );
   set_requirement( (["str":10]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_HEAD);
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_HEADGEAR, C_METAL, C_IRON ]);
}
