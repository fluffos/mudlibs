#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "party hat" )
ALT_NAME( ({"hat","silly hat", "pointy hat"}) )
DISTANT( "a party hat" )
LOOK( "A silly pointy party hat.")
SPECIFIC( "the party hat" )
PLURAL( "party hats" )
ALT_PLURAL( ({ "hats", "silly hats", "pointy hats" }) )
TYPE( "helmet" )
WEIGHT( 100 )
TASTE( "It tastes like a lampshade." )

void create() {
   ::create();
   set_base_ac(5);
   set_ac_mod( (["blunt":10,"mental":50]) );
   set_requirement( (["str":1]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(25);
   set_body_parts(BP_HEAD);
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_HEADGEAR, C_PAPER ]);
}
