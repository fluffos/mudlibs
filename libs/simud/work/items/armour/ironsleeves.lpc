#include <const.h>
#include <const/raceconst.h>
inherit "/battle/armour";

GETTABLE( 1 )
DROPPABLE( 1 )
VALUE(300)
NAME( "pair of iron chain sleeves" )
ALT_NAME( ({"iron sleeves","pair of sleeves","sleeves","chain sleeves"}) )
DISTANT( "a pair of iron chain sleeves" )
LOOK( "Scale-mail at the shoulder, but iron chain down the length of the arm, these sleeves protect you quite well.")
SPECIFIC( "the pair of iron sleeves" )
PLURAL( "pairs of iron chain sleeves" )
TYPE( "sleeves" )
WEIGHT( 5500 ) // 5.5 kg =~ 12 lbs
TASTE( "They taste like elbows." )

void create() {
   ::create();
   set_base_ac(15);
   set_ac_mod( (["slashing":10,"electric":-10]) );
   set_requirement( (["str":5]) );
   set_armour_type( "armour" );
   set_flexible(1);
   set_size(20);
   set_body_parts(BP_ARMS);
}
mapping query_aspects() {
   return ([ C_CLOTHING, C_SLEEVES, C_METAL, C_IRON, C_CHAIN ]);
}
