inherit "/obj/scenery";
#include <container.h>
#include <shape.h>

NAME( "larder" )
SPECIFIC( "the larder" )
DISTANT( "a larder" )
LOOK( "There are 3 sets of wooden, shelf-like, hollow boxes. It is typically used for food storage.?(HASINV: On the larder $(ISINV) $(INV))" )
GETTABLE(0)
DROPPABLE(0)
TASTE( "The taste is a mixture of the foods stored here over the years." )
int query_is_larder() { return 1; }

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a larder ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_paint( object painter ) { }

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "[=]", 2, LAYER_FURNITURE );
}

void on_insert( object ob ) {
   if( ob->query_no_junk() || this_object()->query_held_weight() > 100000 ) {
      ob->move( environment(this_object()) );
	   tell_room( environment(this_object()), "The larder overflows, spilling out " + ob->query_distant() + ".\n" );
	}
}
