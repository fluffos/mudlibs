inherit "/battle/weapon";

NAME( "pick" )
LOOK( "A standard mining pickaxe. The head consists of two sharp pointed ends, and the haft is thick sturdy wood." )
DISTANT( "a pick" )
SPECIFIC( "the pick" )
PLURAL( "picks" )
ALT_NAME( ({ "pickaxe" }) )
ALT_PLURAL( ({ "pickaxes" }) )
TYPE( "weapon" )
WEAPON_TYPE( "axe" )
TASTE( "It's for picking noses, apparently." )

WEIGHT( 2700 )
VALUE( 50 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":4]) );
   set_requirement( (["str":13]) );
}

mapping query_aspects() {
   return ([ C_TOOL, C_WEAPON, C_PICKAXE, C_PICKHEAD, C_HANDLE, C_IRON, C_METAL, C_WOOD, C_ASHWOOD ]);
}
