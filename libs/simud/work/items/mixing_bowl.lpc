#include <const.h>
#include <object.h>
#include <container.h>
#include <saveload.h>
#include <item.h>
#include <desc.h>

DISTANT("a mixing bowl")
SPECIFIC("the mixing bowl")
PLURAL("mixing bowls")
LOOK("A broad, flat mixing bowl, carved from a large single chunk of wood.?(HASINV: Sitting in the bowl $(ISINV) $(INV))")
ALT_NAME( ({ "bowl" }) )
ALT_PLURAL( ({ "bowls" }) )
TASTE( "It tastes like flour." )

void create() {
/* OBJEDIT { */
   set_name("mixing bowl");
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 500 );
   set_bulk_capacity( 3000 );
   set_weight_capacity( 20000 );
   set_value( 30 );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

void on_paint( object painter ) {
//   debug("Painting!");
   painter->paint( query_x(), query_y(), 'o', 3, 1 );
}

mapping query_aspects() {
   return ([ C_WOOD, C_OAKWOOD ]);
}
