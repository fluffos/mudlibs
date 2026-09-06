inherit "/battle/weapon";

NAME( "ceremonial dagger" )
LOOK( "A small silver ceremonial dagger; its blade is twelve inches long, two "+
      "inches wide, and half an inch thick. The platinum blade is shiny. The "+
      "hilt is ornately wrapped with a dragon scale." )
DISTANT( "a ceremonial dagger" )
SPECIFIC( "the ceremonial dagger" )
PLURAL( "ceremonial daggerss" )
TYPE( "weapon" )
WEAPON_TYPE( "dagger" )
TASTE( "Tastes like Fighter." )
ALT_NAME( ({"dagger"}) )

WEIGHT( 400 )
VALUE( 1 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["piercing":-1]) );
   set_requirement( (["cha":10]) );
   set_max_condition(1);
   set_condition(1);
}

mapping query_aspects() {
   return ([ C_WEAPON, C_DAGGER, C_METAL, C_TIN, C_PLATINUM, C_DRAGONSCALE, C_BLADE, C_HILT, C_GUARD, C_POMMEL ]);
}
