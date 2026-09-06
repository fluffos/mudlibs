inherit "/battle/weapon";

NAME( "flail" )
LOOK( "A spiked ball on the end of a chain, suspended from a wooden haft. This would NOT be a good thing to get hit with..." )
DISTANT( "a flail" )
SPECIFIC( "the flail" )
PLURAL( "flails" )
TYPE( "weapon" )
WEAPON_TYPE( "flail" )
TASTE( "It tastes like it would be NOT be a good thing to get hit with..." )

WEIGHT( 4050 )
VALUE( 34 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["blunt":5, "piercing":2]) );
   set_requirement( (["str":11, "dex":12]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_FLAIL, C_METAL, C_IRON, C_HANDLE, C_WOOD, C_ASHWOOD, C_BALL, C_CHAIN ]);
}
