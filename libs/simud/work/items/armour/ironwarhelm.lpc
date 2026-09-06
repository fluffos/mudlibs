#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(490)
NAME( "helm" )
ALT_NAME( ({"helmet","helm","war helm", "iron war helm", "iron helm", "war helm"}) )
DISTANT( "an iron war helm" )
LOOK( "A helm for the advanced warrior; special ridges help guide sword blows away from the head, and reinforcements inside prevent crushing blows. A very strong helmet.")
SPECIFIC( "the iron war helm" )
PLURAL( "iron war helms" )
ALT_PLURAL( ({ "helms" }) )
TYPE( "helmet" )
WEIGHT( 2300 ) // 2.3 kg =~ 5 lbs
TASTE( "This is not what's meant by 'giving head'." )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["edged":10, "blunt":10,"electric":-20]) );
   set_requirement( (["str":11]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_HEAD);
}

mapping query_aspects() {
   return ([ C_CLOTHING, C_HEADGEAR, C_METAL, C_IRON ]);
}
