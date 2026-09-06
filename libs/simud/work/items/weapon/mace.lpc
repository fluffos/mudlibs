inherit "/battle/weapon";

NAME( "mace" )
LOOK( "A sturdy metal haft with a spiked ball on the top. You definately wouldn't wanna get conked on the head with THIS!" )
DISTANT( "a mace" )
SPECIFIC( "the mace" )
PLURAL( "maces" )
TYPE( "weapon" )
WEAPON_TYPE( "mace" )
TASTE( "It tastes like liquid pepper." )

WEIGHT( 3600 )
VALUE( 36 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["blunt":4, "piercing":2]) );
   set_requirement( (["str":14, "dex":13]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_MACE, C_METAL, C_IRON, C_HANDLE, C_BALL ]);
}
