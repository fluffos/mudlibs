inherit "/battle/weapon";

NAME( "greataxe" )
ALT_NAME( ({"axe"}) )
LOOK( "A rather large axe; the haft is an inch thick, and the blade is enormous." )
DISTANT( "a greataxe" )
SPECIFIC( "the greataxe" )
PLURAL( "greataxes" )
ALT_PLURAL( ({ "axes" }) )
TYPE( "weapon" )
WEAPON_TYPE( "axe" )
TASTE( "It tastes like bittersweet memories." )

WEIGHT( 9000 )
VALUE( 85 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":9]) );
   set_requirement( (["str":14, "dex":13]) );
}
mapping query_aspects() {
   return ([ C_WEAPON, C_AXE, C_GREATAXE, C_AXEHEAD, C_HANDLE, C_IRON, C_METAL, C_WOOD, C_ASHWOOD ]);
}
