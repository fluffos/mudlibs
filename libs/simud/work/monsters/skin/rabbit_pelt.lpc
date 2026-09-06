#include <const.h>
inherit "/obj/trinket";

DISTANT( "a rabbit pelt" )
SPECIFIC( "the rabbit pelt" )
LOOK( "This rabbit pelt is covered in rough fur." )
PLURAL( "rabbit pelts" )
ALT_PLURAL( ({"pelts"}) )

void create() {
   ::create();
/* OBJEDIT { */
   set_name( "rabbit pelt" );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 1 );
   set_bulk( 1 );
   set_value( 20 );
set_alt_name( ({ "pelt"  }) );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_PELT, C_RABBITPELT ]);
}
