#include <const.h>
inherit "/obj/ingredient";

TASTE( "It is made from pumpkins and tastes only vaguely intoxicating." )
NAME( "pumpkin beer" )
DISTANT( "pumpkin beer" )
PLURAL( "pumpkin beer" )
SPECIFIC( "the pumpkin beer" )
LOOK( "It is a flat orange-brown colour." )
ALT_NAME( ({ "beer" }) )
ALT_PLURAL( ({ "beer" }) )
FOOD_VALUE( 100 ) // per 1000
DRINK_VALUE( 750 )

FOOD_BUFF( (["str":2, "wil":2, "spd":-1, "dex":-1]) )
FOOD_BUFF_TIME( query_quantity() / 50 )

WEIGHT( 1000 )
BULK( 1000 )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_use_msg( "~Name ~verbtake a hard pull from ~poss pumpkin beer." );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_LIQUID, C_FRUIT ]);
}
