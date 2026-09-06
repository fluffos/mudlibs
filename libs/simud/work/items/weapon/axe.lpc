inherit "/battle/weapon";

NAME( "axe" )
LOOK( "A rounded iron blade, quite sharp, on a short haft. The blade is about the size of a dinner plate." )
DISTANT( "an axe" )
SPECIFIC( "the axe" )
PLURAL( "axes" )
TYPE( "weapon" )
WEAPON_TYPE( "axe" )
TASTE( "~Pron'll just put anything in ~poss mouth, won't ~pron?" )

WEIGHT( 3150 ) // Approx 7lbs
VALUE( 35 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":5, "blunt":2]) );
   set_requirement( (["str":13, "dex":12]) );
}

mapping query_aspects() {
  return ([ C_TOOL, C_WEAPON, C_AXE, C_AXEHEAD, C_HANDLE, C_IRON, C_METAL, C_WOOD, C_ASHWOOD ]);
}
