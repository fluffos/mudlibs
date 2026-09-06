#include <saveload.h>
#include <desc.h>
#include <object.h>
#include <quantity.h>
#include <item.h>

/// If true, this is an amorphous solid, like bread dough, clay, or whatever...
int solid;

void on_move( object src ) {
   ::on_move( src );
   if( !src ) return;
   if( !solid && !environment()->query_container() ) {
      object old_targ;

      old_targ = query_target();
      set_target(this_object());
      if( this_player() )
         this_player()->msg_local( "~CACT~Subt ~vertdissipate as ~name ~verbpour it out.~CDEF" );
      set_target( old_targ );
      destruct( this_object() );
   }
}

string liquid_info() {
   return "solid";
}

int query_gettable() {
   return solid && ::query_gettable();
}

int query_droppable() {
   return solid && ::query_droppable();
}

string query_distant() {
   if( quantity < 5 ) return "a speck of " + ::query_distant();
   if( quantity < 15 ) return "a teaspoon of " + ::query_distant();
   if( quantity < 40 ) return "a tablespoon of " + ::query_distant();
   if( quantity < 110 ) return "a third of a cup of " + ::query_distant();
   if( quantity < 180 ) return "half a cup of " + ::query_distant();
   if( quantity < 350 ) return "a cup of " + ::query_distant();
   if( quantity < 650 ) return "two cups of " + ::query_distant();
   if( quantity < 850 ) return "three cups of " + ::query_distant();
   if( quantity < 1150 ) return "four cups of " + ::query_distant();
   return "a lot of " + ::query_distant();
}

DISTANT("liquid")
SPECIFIC("the liquid")
LOOK("A glob of liquid")
NAME("liquid")
PLURAL("liquid")
WEIGHT(1000)
BULK(1000)
UNIT("mililiter")
UNITS("mililiters")

void create() {
   ::create();
   set_quantity( 250 );
}

int query_solid() {
   return solid;
}

void set_solid( int x ) {
   solid = x;
}

int query_liquid() {
   return 1;
}

int query_weight() {
   return ::query_weight() * query_quantity() / 1000;
}

int query_bulk() {
   return ::query_bulk() * query_quantity() / 1000;
}
