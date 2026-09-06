inherit "/battle/weapon";

NAME( "hatchet" )
LOOK( "A small hand-held axe, the hatchet isn't as powerful as its larger brethren, but its much easier to wield." )
DISTANT( "a hatchet" )
SPECIFIC( "the hatchet" )
PLURAL( "hatchets" )
TYPE( "weapon" )
WEAPON_TYPE( "axe" )
TASTE( "It tastes utilitarian." )

WEIGHT( 2250 )
VALUE( 25 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":6]) );
   set_requirement( (["str":12, "dex":11]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_AXE, C_AXEHEAD, C_HANDLE, C_STEEL, C_METAL, C_WOOD, C_ASHWOOD ]);
}
