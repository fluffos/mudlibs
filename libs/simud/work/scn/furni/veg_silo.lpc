inherit "/obj/scenery";
#include <container.h>
#include <shape.h>

NAME( "veg_silo" )
SPECIFIC( "the vegetable silo" )
DISTANT( "a vegetable silo" )
LOOK( "A silo for storing vegetables.?(HASINV: In the bottom of the silo $(ISINV) $(INV))" )
ALT_NAME( ({"silo", "vegetable silo"}) )
GETTABLE(0)
DROPPABLE(0)

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a vegetable silo ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_paint( object painter ) { }

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "OO", 2, LAYER_FURNITURE );
   painter->paint_shape( query_x(), query_y()+1, "OO", 2, LAYER_FURNITURE );
}

void on_insert( object ob ) {
   if( ob->query_no_junk() || this_object()->query_held_weight() > 100000 ) {
      ob->move( environment(this_object()) );
	   tell_room( environment(this_object()), "The vegetable silo overflows, spilling out " + ob->query_distant() + ".\n" );
	}
}
