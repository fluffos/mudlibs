#include <const.h>
#include <const/raceconst.h>
inherit "/obj/base_armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( "pair of iron boots" )
ALT_NAME( ({"pair of boots","iron boots","boots"}) )
DISTANT( "a pair of iron boots" )
LOOK( "This footwear is made of solid iron plates, held together with bolts. They are fairly heavy, but protect your feet quite well.")
SPECIFIC( "the pair of iron boots" )
PLURAL( "pairs of iron boots" )
TYPE( "boots" )
WEIGHT( 6000 ) // 6 kg =~ 13 lbs.
TASTE( "Do you have any idea where these have been?" )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( (["electric":-10]) );
   set_requirement( (["str":6]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(5);
   set_body_parts(BP_FEET);
   set_aspects( ([ C_CLOTHING, C_SHOES, C_METAL, C_IRON ]) );
}

int query_use_bonuses()
{
   return (query_worn());
}
int query_dex_bonus()
{
   return -3;
}
int query_spd_bonus()
{
   return -1;
}
