inherit "/battle/weapon";

NAME( "plum staff" )
ALT_NAME( ({"staff"}) )
LOOK( "A long twisted staff made from plum wood. Every foot of its length, the staff is bound with a thin ring of silver. At the staff's head is set a small cluster of softly glowing blue crystals." )
DISTANT( "a plum staff" )
SPECIFIC( "the plum staff" )
PLURAL( "plum staves" )
ALT_PLURAL( ({"staves"}) )
TYPE( "weapon" )
WEAPON_TYPE( "polearm" )
TASTE( "It tastes like frozen blueberry jam." )

WEIGHT( 4200 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["blunt":6,"ice":1]) );
   set_requirement( (["dex":12,"int":15]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_WOOD, C_PLUMWOOD, C_STAFF, C_ICE_MANA ]);
}
