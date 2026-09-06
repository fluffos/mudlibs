#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

NAME( "wooden barrel" )
DISTANT( "a wooden barrel" )
SPECIFIC( "the wooden barrel" )
PLURAL( "wooden barrels" )
ALT_NAME( ({ "barrel" }) )
ALT_PLURAL( ({ "barrels" }) )
LOOK( "A large round wooden container.?(HASINV: It contains $(INV).):( It is currently empty.)" )
BULK( 3000 )
WEIGHT( 5000 )
GETTABLE( 1 )
DROPPABLE( 1 )

int query_wrappable() { return 1; }

void create() {
/* OBJEDIT { */
   set_bulk_capacity( 300000 );
   set_weight_capacity( 500000 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_WOOD ]);
}
