inherit "/battle/weapon";

NAME( "cane" )
LOOK( "A solid little walking cane. It has a rough appearance, but the worn handle testifies to its quality and durability." )
DISTANT( "a cane" )
SPECIFIC( "the cane" )
PLURAL( "canes" )
TYPE( "weapon" )
WEAPON_TYPE( "mace" )	// canes are one-handed, not polearms
TASTE( "Roit, I'll do you for that!" )

WEIGHT( 3600 )
VALUE( 5 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_max_condition(300);
   set_condition(300);
   set_wc( (["blunt":2]) );
   set_requirement( (["int":14]), (["wil":12]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_WOOD, C_OAKWOOD, C_CANE ]);
}
