#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "carapace helm" )
ALT_NAME( ({"helmet","helm","carapace helmet"}) )
DISTANT( "a carapace helm" )
LOOK( "This helmet was made by stitching a number of smaller insect or possibly crustacean shells together to cover the head tightly. It looks incredibly light.")
SPECIFIC( "the carapace helm" )
PLURAL( "carapace helms" )
ALT_PLURAL( ({ "helms", "helmets" }) )
TYPE( "helmet" )
WEIGHT( 400 )
TASTE( "It tastes like bug dandruff." )

void create() {
   ::create();
   set_base_ac(30);
   set_ac_mod( (["blunt":10,"piercing":-20]) );
   set_requirement( (["str":6]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_HEAD);
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_HEADGEAR, C_CARAPACE ]);
}
