inherit "/battle/weapon";

NAME( "spear" )
LOOK( "A long wooden pole with a sharp metal tip." )
DISTANT( "a spear" )
SPECIFIC( "the spear" )
PLURAL( "spears" )
TYPE( "weapon" )
WEAPON_TYPE( "polearm" )
TASTE( "It tastes naughty." )

WEIGHT( 4050 )
VALUE( 21 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":6]) );
   set_requirement( (["str":10, "dex":12]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SPEAR, C_WOOD, C_ASHWOOD ]);
}
