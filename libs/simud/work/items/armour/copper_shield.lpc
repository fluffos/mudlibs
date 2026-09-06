#include <const.h>
#include <const/raceconst.h>
inherit "/battle/shield";

NAME( "copper shield" )
ALT_NAME( ({ "shield", "small shield", "small copper shield" }) )
DISTANT( "a small copper shield" )
LOOK("This is a small round copper shield of the sort used by those who wish to interpose a bit of soft metal between themselves and impending harm" )
SPECIFIC( "the copper shield" )
PLURAL( "copper shields" )
ALT_PLURAL( ({ "shields", "small shields", "small copper shields" }) )
WEIGHT( 2000 )
TASTE( "It tastes like buffalo pizza." )

void create() {
   ::create();
   set_base_ac(5);
   set_ac( (["edged":5,"blunt":10]) );
}

mapping query_aspects() {
   return ([ C_METAL, C_COPPER, C_SHIELD ]);
}
