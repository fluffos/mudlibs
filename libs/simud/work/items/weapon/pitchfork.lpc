inherit "/battle/weapon";

NAME( "pitchfork" )
LOOK( "A basic farming tool, with three prongs. Generally used for moving quantities of hay... or entrails." )
DISTANT( "a pitchfork" )
SPECIFIC( "the pitchfork" )
PLURAL( "pitchforks" )
TYPE( "weapon" )
WEAPON_TYPE( "polearm" )
TASTE( "It tastes rural." )

WEIGHT( 2700 )
VALUE( 20 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":5]) );
   set_requirement( (["str":8, "dex":6]) );
}

mapping query_aspects() {
   return ([ C_TOOL, C_WEAPON, C_PITCHFORK, C_WOOD, C_FIRWOOD, C_METAL, C_STEEL ]);
}
