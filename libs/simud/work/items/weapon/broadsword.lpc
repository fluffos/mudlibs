inherit "/battle/weapon";

NAME( "broadsword" )
ALT_NAME( ({ "sword" }) )
LOOK( "A sword with a sharp, wide blade. It's quite heavy." )
DISTANT( "a broadsword" )
SPECIFIC( "the broadsword" )
PLURAL( "broadswords" )
ALT_PLURAL( ({ "swords", "weapons" }) )
TYPE( "weapon" )
WEAPON_TYPE( "sword" )
TASTE( "It tastes pointy." )

WEIGHT( 6750 ) // Approx 15lbs
VALUE( 200 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":7, "blunt":2]) );
   set_requirement( (["str":13, "dex":13]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_SWORD, C_GREATSWORD, C_BLADE, C_POMMEL, C_HILT, C_GUARD, C_METAL, C_STEEL ]);
}
