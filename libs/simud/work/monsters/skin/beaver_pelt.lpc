#include <const.h>
inherit "/obj/trinket";

DISTANT( "a beaver pelt" )
SPECIFIC( "the beaver pelt" )
LOOK( "This is a dark brown beaver pelt. At one time, the beaver pelt was one of the most valued commodities for any trader. Perhaps they can be be used to make a hat or a coat." )
PLURAL( "beaver pelts" )
ALT_PLURAL( ({"pelts"}) )

void create() {
   ::create();
/* OBJEDIT { */
   set_name( "beaver pelt" );
   set_gettable( 1 );
   set_droppable( 1 );
   set_height( 1 );
   set_weight( 1 );
   set_bulk( 1 );
   set_value( 14 );
set_alt_name( ({ "pelt"  }) );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_PELT, C_BEAVERPELT ]);
}
