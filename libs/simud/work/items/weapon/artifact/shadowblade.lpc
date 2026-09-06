inherit "/battle/weapon";

NAME( "shadowblade" )
ALT_NAME( ({"blade"}) )
LOOK( "A blade seemingly made from shadows and mist. A faint mist seems to lift from it, causing a slight haze along the length of the weapon." )
DISTANT( "a shadowblade" )
SPECIFIC( "the shadowblade" )
PLURAL( "shadowblades" )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
ALT_PLURAL( ({ "swords" }) )
TASTE( "Death never tasted so good." )

WEIGHT( 6750 )
VALUE( 211 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":20, "ice":10]) );
   set_requirement( (["str":13, "dex":13]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SWORD, C_GREATSWORD, C_BLADE, C_POMMEL, C_HILT, C_GUARD, C_METAL, C_STEEL ]);
}
