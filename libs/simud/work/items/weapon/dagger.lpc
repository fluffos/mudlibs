inherit "/battle/weapon";

NAME( "dagger" )
LOOK( "A short, sharp, double edged blade on a well-made hilt." )
DISTANT( "a dagger" )
SPECIFIC( "the dagger" )
PLURAL( "daggers" )
TYPE( "weapon" )
WEAPON_TYPE( "dagger" )
TASTE( "~Name should be careful around ~poss eye." )

WEIGHT( 300 ) // .75lbs
VALUE( 8 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":4]) );
   set_requirement( (["dex":10]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_DAGGER, C_METAL, C_STEEL, C_BLADE, C_HILT, C_GUARD, C_POMMEL ]);
}
