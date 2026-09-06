#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "party hat" )
ALT_NAME( ({"hat","silly hat", "pointy hat", "party hat +1"}) )
DISTANT( "a party hat +1" )
LOOK( "A silly pointy party hat. This hat is the highest in silly party technology and fashion, offering way more coolness and funktitude than earlier models of party hat.")
SPECIFIC( "the party hat +1" )
PLURAL( "party hats" )
ALT_PLURAL( ({ "hats", "silly hats", "pointy hats", "party hats +1" }) )
TYPE( "helmet" )
WEIGHT( 100 )
TASTE( "It tastes like a lampshade PLUS ONE!." )

void create() {
   ::create();
   set_base_ac(25);
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
