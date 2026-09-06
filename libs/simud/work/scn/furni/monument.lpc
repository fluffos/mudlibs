#include <coord.h>
#include <shape.h>
#include <object.h>
#include <inven.h>
#include <desc.h>
#include <scenedesc.h>

NAME( "monument" )
DISTANT( "a monument" )
SPECIFIC( "the monument" )
LOOK(
"The monument is a simple altar with a small lantern placed in the middle. "
"The lantern is lit. Carved on the side of the alter are these words:\n\n"
"   Remember this! From a single man's anger\n"
"   Was born a flame that swept the world\n"
"   When we fought one another, it consumed us.\n"
"   When we united, we drowned the fire in the sea.\n"
"   We write this for our descendents, and hope\n"
"   That you will be wiser than we were." )
PLURAL( "monuments" )
PHRASE( "A gorgeous white monument in the middle of things lends an air of solemnity and thoughtfulness." )

int query_scenery() {
   return 1;
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()-1, query_y()-1, "_\t_", 0x80, LAYER_WALL );
   painter->paint_shape( query_x()-2, query_y(), "|___|", 0x70, LAYER_WALL );
   painter->paint( query_x(), query_y()-1, '&', 0x89, LAYER_WALL );
}
