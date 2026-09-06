inherit "/battle/weapon";

NAME( "club" )
LOOK( "A stout wooden club, with one end thick and knotted, and the other wrapped in soft leather for a grip." )
DISTANT( "a club" )
SPECIFIC( "the club" )
PLURAL( "clubs" )
TYPE( "weapon" )
WEAPON_TYPE( "mace" )
TASTE( "It tastes like cavemen." )

WEIGHT( 1800 )
VALUE( 5 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["blunt":4]) );
   set_requirement( (["str":11]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_CLUB, C_WOOD, C_OAKWOOD, C_CLOTH, C_LEATHER  ]);
}
