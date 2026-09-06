#include <object.h>
#include <container.h>
#include <inven.h>
#include <desc.h>
#include <shape.h>
#include <coord.h>

void create() {
/* OBJEDIT { */
   set_name("bookshelf");
   set_distant("a bookshelf");
   set_specific("the bookshelf");
   set_plural("bookshelves");
   set_look("It's a large wooden bookshelf?(HASINV: that contains $(INV)).");
   set_alt_name( "shelf" );
/* } OBJEDIT */
   ::create();
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_shape() {
   return SHAPE_BOX( 3, 1 );
}

void on_map_paint( object painter ) {
   painter->paint_row( query_x(), query_y(), "===", 11, LAYER_FURNITURE );
}
