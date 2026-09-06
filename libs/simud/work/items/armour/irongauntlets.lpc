#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(150)
NAME( "pair of iron gauntlets" )
ALT_NAME( ({"gauntlets","iron gauntlets","pair of gauntlets"}) )
DISTANT( "a pair of iron gauntlets" )
LOOK( "Made completely of iron, these gauntlets are a good deterrence for blades, and protect your hands quite well. These are the perfect gauntlets for the thrifty warrior.")
SPECIFIC( "the pair of iron gauntlets" )
PLURAL( "pairs of iron gauntlets" )
TYPE( "gauntlets" )
WEIGHT( 1400 ) // 1.4 kg =~ 2 lbs
TASTE( "~Name ~verbhas a hard time fitting ~poss tongue down into the fingers." )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["edged":10,"electric":-10]) );
   set_requirement( (["str":10]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(5);
   set_body_parts(BP_HANDS);
}

int query_use_bonuses()
{
   return (query_worn());
}
int query_dex_bonus()
{
   return -3/4;
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_GLOVES, C_METAL, C_IRON ]);
}
