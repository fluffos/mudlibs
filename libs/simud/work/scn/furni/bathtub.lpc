#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>
/*
#include <coord.h>
#include <shape.h>
#include <scenedesc.h>
*/
ALT_NAME( ({"bathtub"}) )
NAME( "tub" )
DISTANT( "a bathtub" )
SPECIFIC( "the bathtub" )
LOOK( "It's a white, porcelain bathtub?(HASINV:, with $(INV) inside.):(. It's empty.)  Erm, yeah you can stop staring at it now." )
PLURAL( "bathtubs" )
ALT_PLURAL( ({"tubs"}) )
GETTABLE( 0 )
DROPPABLE( 1 )

int query_scenery() {
   return 1;
}

void on_map_paint( object painter ) {
   /*painter->paint_shape( query_x(), query_y(), "\t___\n|___|", 15+3*16, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "(", 7, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+2, "###", 15, LAYER_WALL );
   painter->paint_shape( query_x()+4, query_y()+2, ")", 7, LAYER_WALL );*/
   painter->paint_shape( query_x(), query_y(), "\t__\n(", 15+3*16, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+1, "__", 15+7*16, LAYER_WALL );
   painter->paint_shape( query_x()+3, query_y()+1, ")", 15+3*16, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "\t==", 15+3*16, LAYER_WALL );
}
