#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(360)
NAME( "pair of iron leggings" )
ALT_NAME( ({"iron leggings", "pair of leggings", "leggings"}) )
DISTANT( "a pair of iron leggings" )
LOOK( " Jointed plates of iron, curved to fit your legs and strapped on with soft leather. Good for deflecting slashing blows, not good for much else.")
SPECIFIC( "the pair of iron leggings" )
PLURAL( "pairs of iron leggings" )
TYPE( "leggings" )
WEIGHT( 9100 ) // 9.1 kg =~ 20 lbs

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["slashing":10, "lightning":-10]) );
   set_requirement( (["str":8]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(20);
   set_body_parts(BP_LEGS);
}
int query_use_bonuses()
{
   return(query_worn());
}
int query_dex_bonus()
{
   return -1;
}
int query_spd_bonus()
{
   return -2;
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_PANTS, C_METAL, C_IRON, C_CLOTH, C_LEATHER ]);
}
