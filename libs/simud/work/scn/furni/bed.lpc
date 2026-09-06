#include <coord.h>
#include <shape.h>
#include <object.h>
#include <inven.h>
#include <desc.h>
#include <scenedesc.h>
#include <container.h>

//ALT_NAME( ({"bathtub"}) )
NAME( "bed" )
DISTANT( "a bed" )
SPECIFIC( "the bed" )
LOOK( "A layer of dust sits on top of the covers.  It has obviously not been used in some time." )
PLURAL( "beds" )
//ALT_PLURAL( ({""}) )
GETTABLE( 0 )
DROPPABLE( 1 )

int query_scenery() {
   return 1;
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "|==|", 4, LAYER_WALL );
   /*painter->paint_shape( query_x(), query_y(), "\t__\n(", 15+3*16, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+1, "__", 15+7*16, LAYER_WALL );
   painter->paint_shape( query_x()+3, query_y()+1, ")", 15+3*16, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "\t==", 15+3*16, LAYER_WALL );*/
}
