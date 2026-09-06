#include <object.h>
#include <inven.h>
#include <desc.h>
#include <item.h>
#include <lockable.h>
#include <shape.h>

NAME( "wooden gate" )
ALT_NAME( ({ "gate" }) )
DISTANT( "a gate" )
SPECIFIC( "the gate" )
LOOK( "It's a little gate, suitable for opening and closing." )
PLURAL( "gates" )
GETTABLE( 0 )
DROPPABLE( 1 )

void set_closed( int x )
{
   ::set_closed(x);
   // A quick and ugly way to update the pathfinding info.
   if( environment() )
      environment()->clear_map();
}

mapping query_shape() {
   return ([ SMAKE_C(0,0,0) ]);
}

mapping query_border() {
   if( environment() && environment()->query_is_site() ) return query_shape();
   return ::query_border();
}

int query_scenery() {
   return 1;
}

int query_is_razable( object razer ) {
   return 1;
}

int on_raze() {
   if( !environment()->query_can_build() ) return 0;
   this_player()->msg_local( "~CACT~Name ~verbtake apart the gate.~CDEF" );
   destruct(this_object());
   return 1;
}

void on_paint( object painter ) {
   if( query_closed() )
      painter->paint( query_x(), query_y(), query_locked() ? 'x' : '+', 15, LAYER_WALL );
   else
      painter->paint( query_x(), query_y(), '.', 15, LAYER_ROUGH );
}

int query_is_building() {
   return 1;
}
