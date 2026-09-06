#include <coord.h>
#include <shape.h>
#include <object.h>
#include <inven.h>
#include <desc.h>
#include <scenedesc.h>
#include <container.h>

NAME( "fountain" )
DISTANT( "a fountain" )
SPECIFIC( "the fountain" )
LOOK( "It's a white stone fountain full of sparkling, clean water." )
PLURAL( "fountains" )
GETTABLE( 0 )
DROPPABLE( 1 )

void create() {
   ::create();
   if( environment() ) {
      call_out( "do_spray", 2 );
      set_phrase( "There is a white stone fountain ~plac." );
      set_position( "here" );
      set_preposition( "in" );
   }
}

int query_scenery() {
   return 1;
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "\t___", 15+3*16, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "(\t\t\t)", 8+3*16, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+1, ".O.", 14+6*16, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "(\t\t\t)", 8+3*16, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+2, "###", 15+3*16, LAYER_WALL );
}

// from here on was stolen directly from /scn/water/water since including
// doesn't quite work as the water object defines some conflicting scnerey
// settings

int on_fill( object dest ) {
   object water;
   int capacity;

   capacity = dest->query_bulk_capacity() - dest->query_held_bulk();
   if( capacity <= 0 ) {
      msg("It's already full!");
      return 1;
   }
   water = clone_object("/items/drink/water");
   water->set_quantity( capacity );
   water->move( dest );
   set_target( dest );
   this_player()->msg_local("~CACT~Name ~verbfill ~targ with water from the fountain.~CDEF");
   return 1;
}

int query_is_drinkable() {
   return 1;
}

int on_consume( int max ) {
   this_player()->add_drink( max );
   set_target(this_object());
   if( this_player()->query_drink() >= this_player()->query_drink_capacity() )
      this_player()->msg_local("~CACT~Name ~verbdrink ~poss fill from ~targ.~CDEF");
   else
      this_player()->msg_local("~CACT~Name ~verbtake a drink from ~targ.~CDEF");
   return 1;
}
