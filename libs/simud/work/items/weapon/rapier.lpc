inherit "/battle/weapon";

NAME( "rapier" )
ALT_NAME( ({"sword"}) )
LOOK( "Although quite deadly as a piercing weapon, slashing people with this sword wouldn't do much damage, because it has no sharpened edge." )
DISTANT( "a rapier" )
SPECIFIC( "the rapier" )
PLURAL( "rapiers" )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
ALT_PLURAL( ({ "swords", "weapons" }) )
TASTE( "It tastes minty, with a hint of juniper." )

WEIGHT( 1350 )
VALUE( 85 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":6]) );
   set_requirement( (["dex":14]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SWORD, C_RAPIER, C_METAL, C_STEEL ]);
}
