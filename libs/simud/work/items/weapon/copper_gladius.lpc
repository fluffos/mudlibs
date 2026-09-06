inherit "/battle/weapon";

NAME( "gladius" )
ALT_NAME( ({"copper gladius","copper sword","sword","gladius","shortsword"}) )
LOOK( "A short copper sword that flares to a slightly larger blade before the tip." )
DISTANT( "a copper gladius" )
SPECIFIC( "the copper gladius" )
PLURAL( "gladii" )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
ALT_PLURAL( ({ "swords", "weapons", "shortswords", "copper swords", "copper gladii", "gladiuses" }) )
TASTE( "It tastes rather phalaxish." )

WEIGHT( 1800 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":6]) );
   set_requirement( (["str":11, "dex":12]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_METAL, C_COPPER, C_SWORD, C_SHORTSWORD, C_POMMEL, C_BLADE, C_HILT, C_GUARD ]);
}
