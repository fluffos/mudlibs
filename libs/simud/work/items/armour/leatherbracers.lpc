#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(60)
NAME( "pair of leather bracers" )
ALT_NAME( ({"pair of bracers","leather bracers","bracers"}) )
DISTANT( "a pair of leather bracers" )
LOOK( "Stiff leather with designs of twisted knots carved into it... it's held on by laces up the back.")
SPECIFIC( "the pair of leather bracers" )
PLURAL( "pairs of leather bracers" )
TYPE( "bracers" )
WEIGHT( 400 ) // .45kg =~ 1 lb
TASTE( "What a bracing taste!" )

void create() {
   ::create();
   set_base_ac(10);
   set_ac_mod( (["slashing":10]) );
   set_requirement( (["str":1]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts(BP_WRISTS);
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_BRACERS, C_CLOTH, C_LEATHER ]);
}
