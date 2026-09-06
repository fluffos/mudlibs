inherit "/battle/weapon";

NAME( "greatsword" )
ALT_NAME( ({"sword"}) )
LOOK( "This is one big sword. The blade is about 4 feet in length, and quite sharp. Be careful you don't poke your eye out." )
DISTANT( "a greatsword" )
SPECIFIC( "the greatsword" )
PLURAL( "greatswords" )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
ALT_PLURAL( ({ "swords", "weapons" }) )
TASTE( "It tastes like chicken." )

WEIGHT( 6750 )
VALUE( 211 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":8]) );
   set_requirement( (["str":13, "dex":13]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SWORD, C_GREATSWORD, C_BLADE, C_POMMEL, C_HILT, C_GUARD, C_METAL, C_STEEL ]);
}
