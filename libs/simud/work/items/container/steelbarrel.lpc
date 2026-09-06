#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

NAME( "steel barrel" )
DISTANT( "a steel barrel" )
SPECIFIC( "the steel barrel" )
PLURAL( "steel barrels" )
ALT_NAME( ({ "barrel" }) )
ALT_PLURAL( ({ "barrels" }) )
LOOK( "A large round steel container.?(HASINV: It contains $(INV).):( It is currently empty.)" )
BULK( 3000 )
WEIGHT( 5000 )
GETTABLE( 1 )
DROPPABLE( 1 )

int query_wrappable() { return 1; }

void create() {
/* OBJEDIT { */
   set_bulk_capacity( 30000000 );
   set_weight_capacity( 50000000 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_STEEL ]);
}
