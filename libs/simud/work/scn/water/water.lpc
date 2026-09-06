#include <const.h>
#include <inven.h>
#include <desc.h>
#include <object.h>
#include <landscape.h>
#include <scenedesc.h>

NAME( "water" )
LOOK( "Rather ordinary water." )
SPECIFIC( "the water" )
DISTANT( "water" )

int query_tile_num() { return 7; }

int query_is_landscape() { return 1; }

int query_zlayer() { return LAYER_WATER; }

string query_liquid_type()
{
   return "/items/drink/water";
}

int on_fill( object dest ) {
   object water;
   int capacity;

   capacity = dest->query_bulk_capacity() - dest->query_held_bulk();
   if( capacity <= 0 ) {
      msg("It's already full!");
      return 1;
   }
   water = clone_object( query_liquid_type() );
   water->set_quantity( capacity );
   water->move( dest );
   set_target( dest );
   this_player()->msg_local("~CACT~Name ~verbfill ~targ with " + water->query_name() + ".~CDEF");
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
