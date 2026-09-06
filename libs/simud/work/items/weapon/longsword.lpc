inherit "/battle/weapon";

NAME( "longsword" )
ALT_NAME( ({"sword"}) )
LOOK( "A long steel blade on a well-made hilt. You must be dextrous to master the balance of this sword." )
DISTANT( "a longsword" )
SPECIFIC( "the longsword" )
PLURAL( "longswords" )
ALT_PLURAL( ({ "swords", "weapons" }) )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
TASTE( "It tastes knightly." )

WEIGHT( 1800 )
VALUE( 63 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":6]) );
   set_requirement( (["str":12, "dex":13]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SWORD, C_LONGSWORD, C_METAL, C_STEEL, C_BLADE, C_HILT, C_GUARD, C_POMMEL ]);
}
