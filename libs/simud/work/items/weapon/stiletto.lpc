inherit "/battle/weapon";

NAME( "stiletto" )
LOOK( "A long, thin blade sharpened on both edges and narrowing to one of the most stabbingest points imagineable." )
DISTANT( "a stiletto" )
SPECIFIC( "the stiletto" )
PLURAL( "stilettoes" )
TYPE( "weapon" )
WEAPON_TYPE( "dagger" )
TASTE( "~Name should be careful around ~poss eye." )

WEIGHT( 400 ) // 1lbs

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":9]) );
   set_requirement( (["dex":15]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_DAGGER, C_METAL, C_STEEL, C_BLADE, C_HILT, C_GUARD, C_POMMEL ]);
}
