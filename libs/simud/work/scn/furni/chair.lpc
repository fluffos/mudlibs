inherit "/obj/scenery";
#include <container.h>

NAME( "chair" )
SPECIFIC( "the chair" )
DISTANT( "a chair" )
LOOK( "The chair is made of wood, and looks fairly sturdy.?(HASINV: On the chair $(ISINV) $(INV).)" )

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a sturdy wooden chair ~plac." );
   set_position( "here" );
   set_preposition( "on" );
/* } OBJEDIT */
}

int query_can_sit() {
   return 1;
}

void on_map_paint( object painter ) {
   painter->paint( query_x(), query_y(), ')', 11, LAYER_ITEMS );
}
