inherit "/battle/weapon";

NAME( "warhammer" )
LOOK( "A really big hammer! You could do some SERIOUS damage with this... if you knew how to use it." )
DISTANT( "a warhammer" )
SPECIFIC( "the warhammer" )
PLURAL( "warhammers" )
ALT_NAME( ({ "hammer" }) )
TYPE( "weapon" )
WEAPON_TYPE( "mace" )
TASTE( "It tastes like an overpriced miniatures game." )

WEIGHT( 2250 )
VALUE( 51 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["blunt":7]) );
   set_requirement( (["str":10, "dex":11]) );
}

mapping query_aspects() {
   return ([ C_WEAPON, C_HAMMER, C_HANDLE ]);
}
