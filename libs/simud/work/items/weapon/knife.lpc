inherit "/battle/weapon";

NAME( "knife" )
LOOK( "A short, sharp knife such as you might use to cut up your food... or to cut up what you plan to turn INTO your food." )
DISTANT( "a knife" )
SPECIFIC( "the knife" )
PLURAL( "knives" )
TYPE( "weapon" )
WEAPON_TYPE( "dagger" )
TASTE( "It tastes like butter." )

WEIGHT( 300 )
VALUE( 5 )

GETTABLE( 1 )
DROPPABLE( 1 )

void create() {
   ::create();
   set_wc( (["edged":3]) );
   set_requirement( (["str":4]) );
}

mapping query_aspects() {
   return ([ C_TOOL, C_WEAPON, C_KNIFE, C_METAL, C_STEEL, C_HANDLE, C_BLADE ]);
}
