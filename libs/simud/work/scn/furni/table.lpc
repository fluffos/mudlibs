inherit "/obj/scenery";
#include <container.h>

SPECIFIC( "the table" )
DISTANT( "a table" )
LOOK( "The table is made of wood, and looks quite sturdy.?(HASINV: On the table $(ISINV) $(INV).)" )

void create() {
   ::create();
/* OBJEDIT { */
   set_name( "table" );
   set_phrase( "There is a sturdy wooden table ~plac." );
   set_position( "here" );
   set_preposition( "on" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   // Outside rim of the table.
   painter->paint_shape( query_x(), query_y(), ".---.\n|\t\t\t|\n'---'", 0x07, LAYER_FURNITURE );
   // Surface of the table. Paints on "LAYER_BRIDGE" to allow for standing on it, but should
   // still cover up floor patterns.
   painter->paint_shape( query_x()+1, query_y()+1, "   ", 0x07, LAYER_BRIDGE );
}

void on_paint( object painter ) {
   if( first_inventory() ) painter->paint( query_x() + 2, query_y() + 1, '*', 0x0f, LAYER_ITEMS );
}
