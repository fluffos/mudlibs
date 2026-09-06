inherit "/battle/weapon";

NAME( "shortsword" )
ALT_NAME( ({"sword"}) )
LOOK( "A basic, short, metal sword. Very plain." )
DISTANT( "a shortsword" )
SPECIFIC( "the shortsword" )
PLURAL( "shortswords" )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
ALT_PLURAL( ({ "swords", "weapons" }) )
TASTE( "It tastes functional." )

WEIGHT( 1800 )
VALUE( 42 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":5]) );
   set_requirement( (["str":11, "dex":12]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_METAL, C_STEEL, C_SWORD, C_SHORTSWORD, C_POMMEL, C_BLADE, C_HILT, C_GUARD ]);
}
