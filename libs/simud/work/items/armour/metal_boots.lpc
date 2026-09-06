#include <const.h>
#include <const/raceconst.h>
inherit "/obj/base_armour";

GETTABLE( 1 )
DROPPABLE( 1 )
NAME( METAL_TYPE + " boots" )
ALT_NAME( ({"pair of boots", "boots", "footwear", METAL_TYPE + " armour", METAL_TYPE + " armor" }) )
DISTANT( "a pair of " + METAL_TYPE + " boots" )
LOOK( "This footwear is made of solid $(METAL) plates, held together with bolts. They are fairly heavy, but protect your feet quite well.")
SPECIFIC( "the pair of " + METAL_TYPE + " boots" )
PLURAL( "pairs of " + METAL_TYPE + " boots" )
ALT_PLURAL( ({ "boots", "pairs of boots" }) )
TYPE( "armour" )
WEIGHT( 6000 ) // 6 kg =~ 13 lbs.
TASTE( "Do you have any idea where these have been?" )
CONDITION( 1500 )
ASPECT( ([ C_CLOTHING, C_SHOES, C_METAL ]) )

void create() {
   ::create();
   set_base_ac(20);
   set_ac_mod( ([]) );
   set_requirement( (["str":6]) );
   set_armour_type( "armour" );
   set_flexible(0);
   set_size(5);
   set_body_parts(BP_FEET);
}

int query_dex_bonus()
{
   return -3;
}

int query_spd_bonus()
{
   return -1;
}
