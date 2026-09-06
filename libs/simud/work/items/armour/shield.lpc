#include <const.h>
#include <const/raceconst.h>
inherit "/battle/shield";

NAME( "shield" )
VALUE(360)
DISTANT( "a small shield" )
LOOK("This is a small iron shield. Perhaps if you were to strap it on"+
     "to your arm, you might manage to deflect swords and stuff.")
SPECIFIC( "the shield" )
PLURAL( "shields" )
WEIGHT( 2700 ) // 2.7 kg =~ 6 lbs
TASTE( "It doesn't taste much like pizza." )

void create() {
   ::create();
   set_base_ac(10);
   set_ac( (["edged":1,"piercing":1]) );
}

mapping query_aspects() {
   return ([ C_METAL, C_IRON, C_SHIELD ]);
}
