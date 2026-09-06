inherit "/battle/weapon";

NAME( "whip" )
LOOK( "A long, leather whip of the type used for training animals and spurring horses. Not a very effective weapon." )
DISTANT( "a whip" )
SPECIFIC( "the whip" )
PLURAL( "whips" )
TYPE( "weapon" )
WEAPON_TYPE( "flail" )
TASTE( "It tastes like Indiana." )

WEIGHT( 900 )
VALUE( 4 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
/* OBJEDIT { */
   set_wc( (["edged":2]) );
   set_requirement( (["dex":13]) );
/* } OBJEDIT */
}

mapping query_aspects() {
   return ([ C_WEAPON, C_WHIP, C_HANDLE, C_THONG ]);
}
