#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

NAME( "bucket" )
DISTANT( "a bucket" )
SPECIFIC( "the bucket" )
PLURAL( "buckets" )
LOOK( "A sturdy little bucket made of wood. ?(HASINV:It's filled with $(INV).):(It's empty.)" )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 350 )
BULK( 1200 )
VALUE( 80 )
TASTE( "It tastes like well water, ew." )

void create() {
   ::create();
/* OBJEDIT { */
   set_bulk_capacity( 4000 );
   set_weight_capacity( 8000 );
/* } OBJEDIT */
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_WOOD ]);
}
