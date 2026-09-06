inherit "/battle/weapon";

NAME( "staff" )
LOOK( "A stout wooden staff, it is plain an unadorned. Basically, just a big ol' stick." )
DISTANT( "a staff" )
SPECIFIC( "the staff" )
PLURAL( "staves" )
TYPE( "weapon" )
WEAPON_TYPE( "polearm" )
TASTE( "Heheh, ~name said staff." )

WEIGHT( 3600 )
VALUE( 5 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["blunt":4]) );
   set_requirement( (["dex":12]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_WOOD, C_OAKWOOD, C_STAFF ]);
}
