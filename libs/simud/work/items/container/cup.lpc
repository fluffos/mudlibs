#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

TASTE( "No coffee left, unfortunately." )

void create() {
/* OBJEDIT { */
   set_name("cup");
   set_distant("a cup");
   set_specific("the cup");
   set_plural("cups");
   set_look("A gray, stone cup with a handle, suitable for drinking.?(HASINV: It's filled with $(INV).)");
   set_gettable( 1 );
   set_droppable( 1 );
   set_bulk_capacity( 300 );
   set_weight_capacity( 2500 );
   set_weight( 500 );
   set_bulk( 500 );
   set_value( 15 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_STONE ]);
}
