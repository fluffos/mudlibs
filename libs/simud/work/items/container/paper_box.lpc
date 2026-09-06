#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

NAME( "paper box" )
DISTANT( "a paper box" )
SPECIFIC( "the paper box" )
PLURAL( "paper boxes" )
ALT_NAME( ({ "box" }) )
ALT_PLURAL( ({ "boxes" }) )
LOOK( "A small paper box of the variety generally used to compartmentalize small items.?(HASINV: It contains $(INV).):( It is currently empty.)" )
BULK( 1000 )
WEIGHT( 100 )
GETTABLE( 1 )
DROPPABLE( 1 )

int query_wrappable() { return 1; }

void create() {
/* OBJEDIT { */
   set_bulk_capacity( 300 );
   set_weight_capacity( 2500 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_PAPER ]);
}
