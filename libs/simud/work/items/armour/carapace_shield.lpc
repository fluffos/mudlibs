#include <const.h>
#include <const/raceconst.h>
inherit "/battle/shield";

NAME( "carapace shield" )
ALT_NAME( ({ "shield" }) )
DISTANT( "a carapace shield" )
LOOK("This shield was made by overlapping a number of large insect shells and then stiching them to a big sheet of leather. It looks incredibly light as far as shields go and would likely be quite effective in deflecting objects swung or thrown at the wearer in a potentially harmful manner." )
SPECIFIC( "the carapace shield" )
PLURAL( "carapace shields" )
ALT_PLURAL( ({ "shields" }) )
WEIGHT( 1200 )
TASTE( "It tastes like bug pizza." )

void create() {
   ::create();
   set_base_ac(40);
   set_ac( (["blunt":10]) );
}

mapping query_aspects() {
   return ([ C_CARAPACE, C_SHIELD ]);
}
