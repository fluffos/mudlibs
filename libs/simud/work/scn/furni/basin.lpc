inherit "/obj/scenery";
#include <container.h>

NAME( "basin" )
SPECIFIC( "the basin" )
DISTANT( "a basin" )
LOOK( "A carefully carved stone container, the basin is appropriate for all your liquid-storage needs.?(HASINV: In the basin $(ISINV) $(INV).)" )

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a stone basin ~plac." );
   set_position( "here" );
   set_preposition( "in" );
   set_bulk_capacity( 10000 );
   set_weight_capacity( 15000 );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint( query_x(), query_y(), '&', 11, LAYER_FURNITURE );
}
