#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

TASTE( "Tastes like pewter." )

void create() {
/* OBJEDIT { */
   set_name("tankard");
   set_distant("a tankard");
   set_specific("the tankard");
   set_plural("tankards");
   set_look("A dark pewter tankard.?(HASINV: It's filled with $(INV).)");
   set_gettable( 1 );
   set_droppable( 1 );
   set_bulk_capacity( 300 );
   set_weight_capacity( 2500 );
   set_weight( 500 );
   set_bulk( 500 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_LEAD, C_TIN ]);
}
